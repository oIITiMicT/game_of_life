#include "nieghbors.h"

int calc_nieghbors(map *cur, int i, int j) {
    //count the number of live phones in the neighborhood
    int cnt = 0; //count
    if (i > 0) {
        if (j > 0) if (cur->arr[i - 1][j - 1].live) cnt++;
        if (j < cur->m - 1) if (cur->arr[i - 1][j + 1].live) cnt++;
        if (cur->arr[i - 1][j].live) cnt++;
    }
    if (i < cur->n - 1) {
        if (j > 0) if (cur->arr[i + 1][j - 1].live) cnt++;
        if (j < cur->m - 1) if (cur->arr[i + 1][j + 1].live) cnt++;
        if (cur->arr[i + 1][j].live) cnt++;
    }
    if (j > 0) if (cur->arr[i][j - 1].live) cnt++;
    if (j < cur->m - 1) if (cur->arr[i][j + 1].live) cnt++;
    return cnt;
}