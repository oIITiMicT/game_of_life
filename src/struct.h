#ifndef PW_GAME_OF_LIFE_STRUCT_H
#define PW_GAME_OF_LIFE_STRUCT_H

typedef struct element{
    int live;
} Elem;

typedef struct square{
    int length;
    int width;
    Elem **arr;
} Map;

#endif
