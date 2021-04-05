#include "nieghbors.h"

int calc_nieghbors(Map *cur_field, int i, int j) {
    //count the number of live phones in the neighborhood
    int cnt = 0; //count
    if (i > 0) {
        if (j > 0) if (cur_field->arr[i - 1][j - 1].live) cnt++;
        if (j < cur_field->width - 1) if (cur_field->arr[i - 1][j + 1].live) cnt++;
        if (cur_field->arr[i - 1][j].live) cnt++;
    }
    if (i < cur_field->length - 1) {
        if (j > 0) if (cur_field->arr[i + 1][j - 1].live) cnt++;
        if (j < cur_field->width - 1) if (cur_field->arr[i + 1][j + 1].live) cnt++;
        if (cur_field->arr[i + 1][j].live) cnt++;
    }
    if (j > 0) if (cur_field->arr[i][j - 1].live) cnt++;
    if (j < cur_field->length - 1) if (cur_field->arr[i][j + 1].live) cnt++;
    return cnt;
}