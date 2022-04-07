#include <gtk/gtk.h>
#include <stdbool.h>

typedef struct Cell {
    int row;
    int col;
} Cell;

typedef struct Student {
    char name[20];
    bool hasSeat;
    Cell *cell;
} Student;

typedef struct Classroom {
    Student *students;
} Classroom;

#define ROW_COUNT 4
#define COL_COUNT 4
#define MAX_SEATS_COUNT ROW_COUNT*COL_COUNT


int main(int argc, char **argv) {

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *entry[MAX_SEATS_COUNT];
    for (int i = 0; i < MAX_SEATS_COUNT; i++)entry[i] = gtk_entry_new();

    GtkWidget *hbox[ROW_COUNT];
    for (int i = 0; i < ROW_COUNT; i++) {
        hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        gtk_box_set_homogeneous(GTK_BOX(hbox[i]), TRUE);
    }

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);

    GtkWidget *row_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(row_input_box), TRUE);
    GtkWidget *row_entry_input = gtk_entry_new();

    GtkWidget *col_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(col_input_box), TRUE);
    GtkWidget *col_entry_input = gtk_entry_new();

    GtkWidget *capacity_input_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(capacity_input_box), TRUE);

    GtkWidget *input_button = gtk_button_new_with_label("Generate");
    //g_signal_connect(input_button, "clicked", G_CALLBACK(), row_entry_input);

    GtkWidget *full_capacity_button = gtk_button_new_with_label("100% Auslastung");
    //g_signal_connect(input_button, "clicked", G_CALLBACK(), row_entry_input);

    GtkWidget *half_capacity_button = gtk_button_new_with_label("50% Auslastung");
    //g_signal_connect(input_button, "clicked", G_CALLBACK(), row_entry_input);

    GtkWidget *quarter_capacity_button = gtk_button_new_with_label("25% Auslastung");
    //g_signal_connect(input_button, "clicked", G_CALLBACK(), row_entry_input);


    GtkWidget *label_row = gtk_label_new("Anzahl der Reihen");
    GtkWidget *label_col = gtk_label_new("Anzahl der Spalten");


    gtk_box_pack_start(GTK_BOX(capacity_input_box), full_capacity_button, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(capacity_input_box), half_capacity_button, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(capacity_input_box), quarter_capacity_button, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(row_input_box), label_row, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(row_input_box), row_entry_input, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(col_input_box), label_col, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(col_input_box), col_entry_input, 1, 1, 10);


    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COL_COUNT; j++) {
            gtk_box_pack_start(GTK_BOX(hbox[i]), entry[i * COL_COUNT + j], 0, 0, 0);
            gtk_entry_set_width_chars(GTK_ENTRY(entry[i * COL_COUNT + j]), 8); // n_chars 8 e.g ic21b106 = 8 chars
            gtk_entry_set_max_length(GTK_ENTRY(entry[i * COL_COUNT + j]), 8);
        }
    }

    for (int i = 0; i < ROW_COUNT; i++)gtk_box_pack_start(GTK_BOX(vbox), hbox[i], 0, 0, 10);
    gtk_box_pack_start(GTK_BOX(vbox), capacity_input_box, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), row_input_box, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), col_input_box, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), input_button, 1, 1, 10);

    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void display_pattern(int rows, int cols) {

}