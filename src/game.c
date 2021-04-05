#include "game.h"

void game() {
    Map field;
    printf("enter:\n1 - if you want to enter data from the keyboard\n2 - if you want to generate a field\nenter: ");
    int operation;
    scanf("%d", &operation);
    if (operation == 1) {
        printf("enter the number of rows and columns: \n");
        scanf("%d%d", &field.length, &field.width);
        printf("if you want to generate a field - enter 1, if you want to enter it from the keyboard - enter 2\nenter: ");
        scanf("%d", &operation);
        if (operation == 1) {
            generate(&field);
        } else {
            if (operation == 2) {
                printf("enter the start position of the elements (1 - live, 0 - dead):\n");
                field.arr = get_memory(field.arr, field.length, field.width);
                for (int i = 0; i < field.length; i++) {
                    for (int j = 0; j < field.width; j++) {
                        scanf("%d", &field.arr[i][j]);
                    }
                }
            } else {
                printf("ERROR - wrong act number");
                exit(1);
            }
        }
    } else {
        if (operation == 2) {
            field.width = 0;
            field.length = 0;
            generate(&field);
        } else {
            printf("ERROR - wrong act number");
            exit(1);
        }
    }
    solve(&field);
}
