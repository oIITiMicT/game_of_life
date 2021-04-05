#include "evolve.h"

int evolve(Map *cur_field) {
    Elem **new_field;
    new_field = get_memory(new_field, cur_field->length, cur_field->width);
    for (int i = 0; i < cur_field->length; i++) {
        for (int j = 0; j < cur_field->width; j++) {
            int neighbors = calc_nieghbors(cur_field, i, j);
            new_field[i][j] = cur_field->arr[i][j];
            if (neighbors == 3) {
                new_field[i][j].live = 1;
            }
            if (neighbors < 2 || neighbors > 3) {
                new_field[i][j].live = 0;
            }
        }
    }
    int check = 0; //check = 0 - nothing changed
    // checking for changes in the field
    for (int i = 0; i < cur_field->length; i++) {
        for (int j = 0; j < cur_field->width; j++) {
            if (new_field[i][j].live != cur_field->arr[i][j].live) {
                check = 1; //check = 1 - there were some changes on the field
                break;
            }
        }
    }
    cur_field->arr = new_field;
    return check;
}
