#include <gtk/gtk.h>

int main(int argc, char **argv){

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *entry[25];
    for(int i = 0; i < 25; i++)entry[i] = gtk_entry_new();
    
    GtkWidget *hbox[5];
    for(int i = 0; i < 5; i++){
        hbox[i] = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

        gtk_box_set_homogeneous(GTK_BOX(hbox[i]), TRUE);
    }

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);

    GtkWidget *hbox_input = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(hbox_input), TRUE);

    GtkWidget *entry_input  = gtk_entry_new();
    GtkWidget *button_input = gtk_button_new_with_label("Generate");
    //g_signal_connect(button_input, "clicked", G_CALLBACK(), entry_input);

    gtk_box_pack_start(GTK_BOX(hbox_input), entry_input, 1, 1, 10);
    gtk_box_pack_start(GTK_BOX(hbox_input), button_input, 1, 1, 10);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            
            gtk_box_pack_start(GTK_BOX(hbox[i]),entry[i * 5 + j], 0, 0, 0); 

            gtk_entry_set_width_chars(GTK_ENTRY(entry[i * 5 + j]), 2);

            gtk_entry_set_max_length(GTK_ENTRY(entry[i * 5 + j]), 2);
        }
    }


    for(int i = 0; i < 5; i++)gtk_box_pack_start(GTK_BOX(vbox), hbox[i], 0, 0, 0);

    gtk_box_pack_start(GTK_BOX(vbox), hbox_input, 0, 0, 0); 

    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
