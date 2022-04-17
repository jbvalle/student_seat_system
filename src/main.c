#include <gtk/gtk.h>
#include <stdbool.h>
#include <errno.h>

/*
//TODO: 1) when "save" button is selected classroom will be created and the entry are not more editable, only appear as label
        2) create a view3 where the user can ask for direct and indirect neighbour
        3) create a callback function, that saves the generated pattern in create_view2();

*/
typedef struct Cell {
    int row;
    int col;
} Cell;

typedef struct Student {
    char name[20];
    bool hasSeat;
    Cell cell;
} Student;

typedef struct Classroom {
    Student *students;
} Classroom;

typedef struct Widget {
    GtkWidget *view1;
    GtkWidget *view2;
    GtkWidget *view3;
    GtkWidget *frame;
    GtkWidget *col_entry_input;
    GtkWidget *row_entry_input;
    GtkWidget **entry;
    gint row;
    gint col;
} MyWidget;

static void
display_pattern(int rows, int cols, GtkWidget *window, GtkWidget **entry, GtkWidget **hbox, GtkWidget *vbox);
static void remove_child_widget(GtkWidget *widget);



static GtkWidget *create_view1(void);

static GtkWidget *create_view2(MyWidget *widget);

static GtkWidget *create_view3(MyWidget *widget);

static void change_view(GtkWidget *button, gpointer data);

static void radio_button_selected(GtkWidget *widget, gpointer data);

static void get_col_entry_input(GtkWidget *widget, gpointer data);

static void get_row_entry_input(GtkWidget *widget, gpointer data);

static void get_student_name_entry_input(GtkWidget *widget, gpointer data);

#define ROWS_DEFAULT 2
#define COLS_DEFAULT 2
#define MAX_SEATS_COUNT ROWS_DEFAULT*COLS_DEFAULT


static MyWidget *views;
Classroom *classroom;
static int reference_cnt_view1 = 0;
static int reference_cnt_view2 = 0;
static int reference_cnt_view3 = 0;


int main(int argc, char **argv) {
    views = malloc(sizeof(*views));
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    views->view1 = create_view1();
    views->frame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    g_object_ref (views->view1);

    g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_box_pack_start(GTK_BOX (views->frame), views->view1, 10, 10, 10);
    gtk_box_pack_start(GTK_BOX (vbox), views->frame, 10, 10, 10);

    gtk_widget_set_size_request(window, 400, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);

    gtk_container_add(GTK_CONTAINER (window), vbox);
    gtk_widget_show_all(window);

    gtk_main();
    printf("%d\n",reference_cnt_view1);
    printf("%d\n",reference_cnt_view2);
    printf("%d\n",reference_cnt_view3);


    for (int i = 0; i < reference_cnt_view1; ++i) {
        g_object_ref_sink(G_OBJECT(views->view1)); // convert floating ref to standard ref
        gtk_widget_destroy (views->view1); // break external references
        g_object_unref (G_OBJECT(views->view1));
    }
    /*
    for (int i = 0; i < reference_cnt_view2; ++i) {
        g_object_ref_sink(G_OBJECT(views->view2)); // convert floating ref to standard ref
        gtk_widget_destroy (views->view2); // break external references
        g_object_unref (G_OBJECT(views->view2));
    }*//*
    for (int i = 0; i < reference_cnt_view3; ++i) {
        g_object_ref_sink(G_OBJECT(views->view3)); // convert floating ref to standard ref
        gtk_widget_destroy (views->view3); // break external references
        g_object_unref (G_OBJECT(views->view3));
    }
*/
    return 0;
}

static GtkWidget *create_view1(void) {
    GtkWidget *window = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *generate_button = gtk_button_new_with_label("generate");
    GtkWidget *row_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *col_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *label_row = gtk_label_new("Number of rows");
    GtkWidget *label_col = gtk_label_new("Number of cols");
    GtkWidget *label_capacity = gtk_label_new("Capacity: ");
    GtkWidget *radio_button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    views->row_entry_input = gtk_entry_new();
    views->col_entry_input = gtk_entry_new();

    GtkWidget *radio_button = gtk_radio_button_new_with_label(NULL, "100 % ");
    GtkWidget *radio_button1 = gtk_radio_button_new_with_label(
            gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button)), "50 % ");
    GtkWidget *radio_button2 = gtk_radio_button_new_with_label(
            gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button)), "25 % ");


    g_signal_connect(generate_button, "clicked", G_CALLBACK(get_row_entry_input), views);
    g_signal_connect(generate_button, "clicked", G_CALLBACK(get_col_entry_input), views);
    g_signal_connect (generate_button, "clicked", G_CALLBACK(change_view), "2");
    g_signal_connect (radio_button, "toggled", G_CALLBACK(radio_button_selected), (gpointer) "1");
    g_signal_connect (radio_button1, "toggled", G_CALLBACK(radio_button_selected), (gpointer) "2");
    g_signal_connect (radio_button2, "toggled", G_CALLBACK(radio_button_selected), (gpointer) "3");

    gtk_box_pack_start(GTK_BOX(radio_button_box), label_capacity, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(radio_button_box), radio_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(radio_button_box), radio_button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(radio_button_box), radio_button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(row_input_box), label_row, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(row_input_box), views->row_entry_input, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(col_input_box), label_col, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(col_input_box), views->col_entry_input, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(vbox), radio_button_box, TRUE, false, 10);
    gtk_box_pack_start(GTK_BOX(vbox), row_input_box, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), col_input_box, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), generate_button, 0, 0, 10);

    gtk_box_set_homogeneous(GTK_BOX(col_input_box), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(row_input_box), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(radio_button_box), TRUE);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_set_border_width(GTK_CONTAINER (window), 40);
    gtk_widget_set_size_request(window, 1400, 900);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);

    return window;
}

static GtkWidget *create_view2(MyWidget *widget) {
    if (widget->row <= 0 || widget->col <= 0) {
        widget->row = ROWS_DEFAULT; // default when user does not type anything or enters 0
        widget->col = COLS_DEFAULT; // default when user does not type anything or enters 0
    }
    const int NUMBER_OF_STUDENTS = widget->row * widget->col;

    GtkWidget *window = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *option_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *return_button = gtk_button_new_with_label("back");
    GtkWidget *save_button = gtk_button_new_with_label("save");

    GtkWidget **image = malloc(NUMBER_OF_STUDENTS * (sizeof(GtkWidget)));
    GtkWidget **hbox = malloc(widget->row * (sizeof(GtkWidget)));
    GtkWidget **student_container = malloc(widget->row * (sizeof(GtkWidget)));
    widget->entry = malloc(NUMBER_OF_STUDENTS * (sizeof(GtkWidget)));

    if (hbox == NULL || student_container == NULL || image == NULL || widget->entry == NULL) {
        perror("malloc -> ");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < widget->row; i++) {
        hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(hbox[i]), TRUE);
    }
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        widget->entry[i] = gtk_entry_new();
        image[i] = gtk_image_new_from_file("../resources/icon.png");
    }

    for (int i = 0; i < widget->row; i++) {
        for (int j = 0; j < widget->col; j++) {
            student_container[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
            gtk_box_set_homogeneous(GTK_BOX(student_container[i]), TRUE);
            gtk_box_pack_start(GTK_BOX(student_container[i]), image[i * widget->col + j], 0, 0, 0);
            gtk_box_pack_start(GTK_BOX(student_container[i]), widget->entry[i * widget->col + j], 0, 0, 0);
            gtk_box_pack_start(GTK_BOX(hbox[i]), student_container[i], 0, 0, 0);
            gtk_entry_set_width_chars(GTK_ENTRY(widget->entry[i * widget->col + j]),
                                      8); // n_chars 8 e.g ic21b106 = 8 chars
            gtk_entry_set_max_length(GTK_ENTRY(widget->entry[i * widget->col + j]),
                                     8); // n_chars 8 e.g ic21b106 = 8 chars
        }
    }
    for (int i = 0; i < widget->row; i++)
        gtk_box_pack_start(GTK_BOX(vbox), hbox[i], 0, 0, 10);

    g_signal_connect (return_button, "clicked", G_CALLBACK(change_view), "1");
    g_signal_connect (save_button, "clicked", G_CALLBACK(get_student_name_entry_input), widget);
    g_signal_connect (save_button, "clicked", G_CALLBACK(change_view), "3");


    gtk_box_pack_start(GTK_BOX(option_box), return_button, 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(option_box), save_button, 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(vbox), option_box, 1, 1, 5);

    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(option_box), TRUE);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_set_border_width(GTK_CONTAINER (window), 40);
    gtk_widget_set_size_request(window, 1400, 900);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);


    free(image);
    free(student_container);
    free(hbox);

    return window;
}

static GtkWidget *create_view3(MyWidget *widget) {
    const int NUMBER_OF_STUDENTS = widget->row * widget->col;

    GtkWidget *window = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *student_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *input_button = gtk_button_new_with_label("Direkte / Indirekt Nachbar Abfragen");
    GtkWidget *student_entry_input = gtk_entry_new();
    GtkWidget *student_label = gtk_label_new("Martikelnummer eingeben:");

    GtkWidget **label_students_names = malloc(NUMBER_OF_STUDENTS * (sizeof(GtkWidget)));
    GtkWidget **image = malloc(NUMBER_OF_STUDENTS * (sizeof(GtkWidget)));
    GtkWidget **student_container = malloc(widget->row * (sizeof(GtkWidget)));
    GtkWidget **hbox = malloc(widget->row * (sizeof(GtkWidget)));


    if (hbox == NULL || student_container == NULL || image == NULL || label_students_names == NULL) {
        perror("malloc -> ");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < widget->row; i++) {
        hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(hbox[i]), TRUE);
    }


    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        label_students_names[i] = gtk_label_new(classroom->students[i].name);
        if (classroom->students[i].hasSeat)
            image[i] = gtk_image_new_from_file("../resources/icon.png");
        else
            image[i] = gtk_image_new_from_file("../resources/delete.png");
    }

    for (int i = 0; i < widget->row; i++) {
        for (int j = 0; j < widget->col; j++) {
            student_container[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
            gtk_box_set_homogeneous(GTK_BOX(student_container[i]), TRUE);
            gtk_box_pack_start(GTK_BOX(student_container[i]), image[i * widget->col + j], 0, 0, 0);
            gtk_box_pack_start(GTK_BOX(student_container[i]), label_students_names[i * widget->col + j], 0, 0, 0);
            gtk_box_pack_start(GTK_BOX(hbox[i]), student_container[i], 0, 0, 0);
        }
    }
    for (int i = 0; i < widget->row; i++)
        gtk_box_pack_start(GTK_BOX(vbox), hbox[i], 0, 0, 10);

    gtk_box_pack_start(GTK_BOX(student_input_box), student_label, 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(student_input_box), student_entry_input, 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(student_input_box), input_button, 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(vbox), student_input_box, 0, 0, 10);

    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(student_input_box), TRUE);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_set_border_width(GTK_CONTAINER (window), 40);
    gtk_widget_set_size_request(window, 1400, 900);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);

    free(label_students_names);
    free(image);
    free(student_container);
    free(hbox);

    return window;
}

static void change_view(GtkWidget *button, gpointer data) {
    if (strcmp((char *) data, "1") == 0) {
        gtk_container_remove(GTK_CONTAINER (views->frame), views->view2);
        g_object_ref (views->view1);
        reference_cnt_view1++;
        //gtk_box_pack_start(GTK_BOX(views->frame), views->view1, 10, 10, 10);
        gtk_container_add(GTK_CONTAINER(views->frame),views->view1);
        g_object_unref (views->view1);
    }
    if (strcmp((char *) data, "2") == 0) {
        views->view2 = create_view2(views);
        gtk_container_remove(GTK_CONTAINER (views->frame), views->view1);
        g_object_ref (views->view2);
        reference_cnt_view2++;
        //gtk_box_pack_start(GTK_BOX(views->frame), views->view2, 10, 10, 10);
        gtk_container_add(GTK_CONTAINER(views->frame),views->view2);
        g_object_unref (views->view2);

    }
    if (strcmp((char *) data, "3") == 0) {
        views->view3 = create_view3(views);
        gtk_container_remove(GTK_CONTAINER (views->frame), views->view2);
        g_object_ref (views->view3);
        reference_cnt_view3++;
        //gtk_box_pack_start(GTK_BOX(views->frame), views->view3, 10, 10, 10);
        gtk_container_add(GTK_CONTAINER(views->frame),views->view3);
        g_object_unref (views->view3);
    }
}

//TODO: censor the seats when e.g 25 % capacity is selected
void radio_button_selected(GtkWidget *widget, gpointer data) {
    if (strcmp((char *) data, "1") == 0) { // 100 %
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
            g_print("Index %s button 1 is active \n", (char *) data);
        }
    } else if (strcmp((char *) data, "2") == 0) { // 50 %
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
            g_print("Index %s button 2 is active \n", (char *) data);
        }
    } else if (strcmp((char *) data, "3") == 0) { // 25 %
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (widget))) {
            g_print("Index %s button 3 is active \n", (char *) data);
        }
    }
}

gint convert_str_to_int(const gchar *tmp) {
    gchar *end_ptr; // for strTol.
    gdouble result;
    errno = 0;

    result = g_strtod(tmp, &end_ptr);
    if (end_ptr == tmp) {
        //fprintf(stderr, "no digits found\n");
        return -1;
    }
    return (gint) result;
}

void get_col_entry_input(GtkWidget *widget, gpointer data) {
    if (data == NULL)
        return;
    MyWidget *myWidget = data;
    myWidget->col = convert_str_to_int(gtk_entry_get_text(GTK_ENTRY(myWidget->col_entry_input)));
    //  printf("%d col\n", myWidget->col);
}

void get_row_entry_input(GtkWidget *widget, gpointer data) {
    if (data == NULL)
        return;
    MyWidget *myWidget = data;
    myWidget->row = convert_str_to_int(gtk_entry_get_text(GTK_ENTRY(myWidget->row_entry_input)));
//    printf("%d row\n", myWidget->row);
}

void get_student_name_entry_input(GtkWidget *widget, gpointer data) {
    if (data == NULL)
        return;
    MyWidget *myWidget = data;
    const int NUMBER_OF_STUDENTS = myWidget->row * myWidget->col;
    int student_count = 0;

    classroom = malloc(sizeof(Classroom));
    classroom->students = (Student *) malloc(NUMBER_OF_STUDENTS * sizeof(Student));


    for (int i = 0; i < myWidget->row; i++)
        for (int j = 0; j < myWidget->col; j++) {
            strcpy(classroom->students[student_count].name,
                   gtk_entry_get_text(GTK_ENTRY(myWidget->entry[i * myWidget->col + j])));
            if (strcmp(classroom->students[student_count].name, "") != 0) {
                classroom->students[student_count].cell.row = i;
                classroom->students[student_count].cell.col = j;
                classroom->students[student_count].hasSeat = true;
            } else
                classroom->students[student_count].hasSeat = false;
            student_count++;
        }
}


/*
 * #####################################################################################################################
 *                      functions below  ->   not used
 */
void display_pattern(int rows, int cols, GtkWidget *window, GtkWidget **entry, GtkWidget **hbox, GtkWidget *vbox) {
    const int NUMBER_OF_STUDENTS = rows * cols;
    if (rows * cols > MAX_SEATS_COUNT) {
        GtkWidget **entry_safe;
        entry_safe = (GtkWidget **) realloc(entry, NUMBER_OF_STUDENTS * sizeof(GtkWidget));
        if (entry_safe == NULL) { // reallocated pointer ptr1
            free(entry);
            exit(1);
        } else {
            entry = entry_safe;           // the reallocation succeeded, we can overwrite our original pointer now
        }
    }
    if (rows > ROWS_DEFAULT) {
        GtkWidget **hbox_safe;
        hbox_safe = (GtkWidget **) realloc(entry, NUMBER_OF_STUDENTS * sizeof(GtkWidget));
        if (hbox_safe == NULL) { // reallocated pointer ptr1
            free(entry);
            exit(1);
        } else {
            hbox = hbox_safe;           // the reallocation succeeded, we can overwrite our original pointer now
        }
    }

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)entry[i] = gtk_entry_new();
    GtkWidget *vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(vbox1), TRUE);

    for (int i = 0; i < rows; i++) {
        hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(hbox[i]), TRUE);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            gtk_box_pack_start(GTK_BOX(hbox[i]), entry[i * cols + j], 0, 0, 0);
            gtk_entry_set_width_chars(GTK_ENTRY(entry[i * cols + j]), 8); // n_chars 8 e.g ic21b106 = 8 chars
            gtk_entry_set_max_length(GTK_ENTRY(entry[i * cols + j]), 8);
        }
    }
    for (int i = 0; i < rows; i++)gtk_box_pack_start(GTK_BOX(vbox1), hbox[i], 0, 0, 10);
    remove_child_widget(window);
    //gtk_box_pack_start(GTK_BOX(vbox), vbox1, 0, 0, 10);
    //vbox = vbox1;
    gtk_container_add(GTK_CONTAINER(window), vbox1);

}

void remove_child_widget(GtkWidget *widget) {
    GList *children, *iter;
    int index = 0;

    children = gtk_container_get_children(GTK_CONTAINER(widget));
    for (iter = children; iter != NULL; iter = g_list_next(iter)) {
        // if (index == 2)
        //   break;
        gtk_widget_destroy(GTK_WIDGET(iter->data));
        //index++;
    }
    g_list_free(children);
}