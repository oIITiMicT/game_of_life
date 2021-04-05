#include "alloc.h"

Elem** get_memory(Elem **arr, int length, int width) {
    arr = (Elem**)malloc(sizeof(Elem*) * length);
    for (int i = 0; i < length; i++) {
        arr[i] = (Elem*)malloc(sizeof(Elem*) * width);
    }
    return arr;
}
