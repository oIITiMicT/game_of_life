#include "generator.h"

void generate(Map* cur_field) {
    const int minimum_size = 10;
    const int maximum_size = 100;
    const int generation_divider = 4;  // generation chance is determined by dividing 100% by generation_divider
    if (!cur_field->length) cur_field->length = minimum_size + rand() % (maximum_size - minimum_size + 1);
    if (!cur_field->width) cur_field->width = minimum_size + rand() % (maximum_size - minimum_size + 1);
    cur_field->arr = get_memory(cur_field->arr, cur_field->length, cur_field->width);
    for (int i = 0 ; i < cur_field->length; i++) {
        for (int j = 0; j < cur_field->width; j++) {
            cur_field->arr[i][j].live = rand() % generation_divider == 0 ? 1 : 0;
        }
    }
}
