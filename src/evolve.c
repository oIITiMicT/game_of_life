#include "evolve.h"

int evolve(map* cur) {
    elem **new;
    new = get_memory(new, cur->n, cur->m);
    for (int i = 0; i < cur->n; i++) {
        for (int j = 0; j < cur->m; j++) {
            int nieghnors = calc_nieghbors(cur, i, j);
            new[i][j] = cur->arr[i][j];
            if (nieghnors == 3) {
                new[i][j].live = 1;
            }
            if (nieghnors < 2 || nieghnors > 3) {
                new[i][j].live = 0;
            }
        }
    }
    int k = 0; //k = 0 - nothing changed
    // checking for changes in the field
    for (int i = 0; i < cur->n; i++) {
        for (int j = 0; j < cur->m; j++) {
            if (new[i][j].live != cur->arr[i][j].live) {
                k = 1; //k = 1 - there were some changes on the field
                break;
            }
        }
    }
    cur->arr = new;
    return k;
}
