#ifndef GRUPPE_V_PROJECT_FUNCTION_H
#define GRUPPE_V_PROJECT_FUNCTION_H

#include <gtk/gtk.h>
#include <stdbool.h>

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
    int number_of_students;
} Classroom;

typedef struct StudentEntry {
    GtkWidget *entry;
    const gchar *name;
    bool found;
    Cell cell;
} StudentEntry;

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

#define ROWS_DEFAULT 2
#define COLS_DEFAULT 2
#define MAX_SEATS_COUNT ROWS_DEFAULT*COLS_DEFAULT

MyWidget *widget;
Classroom *classroom;

GtkWidget *create_view1(MyWidget *view);

GtkWidget *create_view2(MyWidget *view);

GtkWidget *create_view3(MyWidget *widget);

void create_view4(MyWidget *view, StudentEntry *current_StudentEntry);

void change_view(GtkWidget *button, gpointer data);

void radio_button_selected(GtkWidget *widget, gpointer data);

void get_col_entry_input(GtkWidget *widget, gpointer data);

void get_row_entry_input(GtkWidget *widget, gpointer data);

void get_student_name_entry_input(GtkWidget *widget, gpointer data);

void get_direct_neighbour();

#endif //GRUPPE_V_PROJECT_FUNCTION_H
