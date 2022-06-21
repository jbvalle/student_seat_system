/**
 *@file project_function.h
 *@brief Contains all structs and prototypes of implemented functions
 */
#ifndef GRUPPE_V_PROJECT_FUNCTION_H
#define GRUPPE_V_PROJECT_FUNCTION_H

#include <gtk/gtk.h>
#include <stdbool.h>

/**
 * Saves Student Coordinates
 */
typedef struct Cell {
    int row;
    int col;
} Cell;

/**
 * Containes all students names, occupied seats and coordinates
 */
typedef struct Student {
    char name[20];
    bool hasSeat;
    Cell cell;
} Student;

/**
 * Containes an array of students and its total number
 */
typedef struct Classroom {
    Student *students;
    int number_of_students;
} Classroom;

/**
 * Contains user input of student ID -> is used for fetching entry and saving direct and indirect Neighbours
 *
 */
typedef struct StudentEntry {
    GtkWidget *entry;
    const gchar *name;
    bool found;
    Cell cell;
    char directIndirectNeighbour[25][20];
} StudentEntry;

/**
 * Contains all windows and its gui objects as well as all its variables 
 *
 */
typedef struct Widget {

    /**1. Window: User selects coverage, rows & Cols*/
    GtkWidget *view;
    /**2. Window: User Input Student ID*/
    GtkWidget *view2;
    /**3. Window: Generated Pattern is displayed*/
    GtkWidget *view3;
    GtkWidget *frame;
    GtkWidget *col_entry_input;
    GtkWidget *row_entry_input;
    GtkWidget **entry;
    GtkWidget **image;
    int user_choice;
    gint row;
    gint col;
} MyWidget;

#define ROWS_DEFAULT 4
#define COLS_DEFAULT 4
#define MAX_SEATS_COUNT ROWS_DEFAULT*COLS_DEFAULT

MyWidget *widget;
Classroom *classroom;

GtkWidget *create_view1(MyWidget *view);

GtkWidget *create_view2(MyWidget *view);

GtkWidget *create_view3(MyWidget *view);

void create_view4(MyWidget *view, StudentEntry *current_StudentEntry);

void change_view(GtkWidget *button, gpointer data);

void radio_button_selected(GtkWidget *button, gpointer data);

void get_col_entry_input(GtkWidget *button, gpointer data);

void get_row_entry_input(GtkWidget *button, gpointer data);

void get_student_name_entry_input(GtkWidget *button, gpointer data);

void get_student_entry_input(GtkWidget *button, gpointer data);

bool validate_user_input(StudentEntry *student_entry_input, Classroom *current_classroom);

void get_direct_neighbour();


Classroom* generate_25p_coverage_pattern(Classroom *classroom, MyWidget *myWidget);
Classroom* generate_50p_coverage_pattern(Classroom *classroom, MyWidget *myWidget);
Classroom* generate_100p_coverage_pattern(Classroom *classroom, MyWidget *myWidget);


int gtk_gui_main(int argc, char **argv);

#endif //GRUPPE_V_PROJECT_FUNCTION_H
