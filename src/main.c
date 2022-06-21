/**
 *@file main.c
 *@brief executes main gtk graphical user interface
 */

#include <gtk/gtk.h>
#include "../inc/project_function.h"

/*
//TODO: 1) when "save" button is selected classroom will be created and the entry are not more editable, only appear as label
        2) create a view3 where the user can ask for direct and indirect neighbour
        3) create a callback function, that saves the generated pattern in create_view2();
*/

static void
display_pattern(int rows, int cols, GtkWidget *window, GtkWidget **entry, GtkWidget **hbox, GtkWidget *vbox);

_Noreturn static void remove_child_widget(GtkWidget *widget);


int main(int argc, char **argv) {

    gtk_gui_main(argc, argv);

    return 0;
}
/*
  printf("%d\n", reference_cnt_view1);
  printf("%d\n", reference_cnt_view2);
  printf("%d\n", reference_cnt_view3);
*/
/* ONLY FOR MEMORY_LEAK_PURPOSE */
/*
    for (int i = 0; i < reference_cnt_view1; ++i) {
        g_object_ref_sink(G_OBJECT(widget->view1)); // convert floating ref to standard ref
        gtk_widget_destroy(widget->view1); // break external references
        g_object_unref(G_OBJECT(widget->view1));
    }
    */
/*
for (int i = 0; i < reference_cnt_view2; ++i) {
    g_object_ref_sink(G_OBJECT(widget->view2)); // convert floating ref to standard ref
    gtk_widget_destroy (widget->view2); // break external references
    g_object_unref (G_OBJECT(widget->view2));
}*//*
    for (int i = 0; i < reference_cnt_view3; ++i) {
        g_object_ref_sink(G_OBJECT(widget->view3)); // convert floating ref to standard ref
        gtk_widget_destroy (widget->view3); // break external references
        g_object_unref (G_OBJECT(widget->view3));
    }
*/
