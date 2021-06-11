#include "solver.h"

void solve(Map* field) {
    const int height = field->length;
    const int weight = field->width;
    ge_GIF *gif = ge_new_gif(
            "ans.gif",       // file name 
            weight, height,  // canvas size
            (uint8_t []) {   // palette
                    0x00, 0x00, 0x00,  // 0 -> black
                    0xFF, 0xFF, 0xFF,  // 1 -> white
                    0x00, 0xFF, 0x00,  // 2 -> green
                    0x00, 0x00, 0xFF,  // 3 -> blue
            },
            2,  // palette depth == log2(# of colors)
            0   // infinite loop
    );

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            gif->frame[i * weight + j] = 1;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            if (field->arr[i][j].live == 1) gif->frame[i * weight + j] = 0;
        }
    }

    int cur_day = 0;
    ge_add_frame(gif, 10);
    while (cur_day < 500) {
        const int now = evolve(field);
        if (!now) {
            break;
        }

        cur_day++;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                gif->frame[i * weight + j] = 1;
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                if (field->arr[i][j].live == 1) gif->frame[i * weight + j] = 0;
            }
        }
        ge_add_frame(gif, 10);
    }
    ge_close_gif(gif);
}