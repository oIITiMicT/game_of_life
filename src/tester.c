#include "tester.h"


void test(int cnt) {
    for (int q = 0; q < cnt; q++) {
        map test;
        generate(&test);
        int w = test.n, h = test.m;
        char num = q + '0';
        ge_GIF *gif = ge_new_gif(
                "test.gif",
                w, h,
                (uint8_t []) {
                        0x00, 0x00, 0x00,
                        0xFF, 0xFF, 0xFF,
                },
                2,
                0
        );

        int day = 0;
        printf("day №%d\n", day);
        for (int i = 0;i < test.n; i++) {
            for (int j = 0; j < test.m; j++) {
                printf("%d ", test.arr[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < test.n; i++) {
            for (int j = 0; j < test.m; j++) {
                gif->frame[i * test.n + j] = test.arr[i][j].live;
            }
        }
        ge_add_frame(gif, 1);
        while (day < 100) {
            day++;
            int now = evolve(&test);
            if (!now) break;
            printf("day №%d\n", day);
            for (int i = 0;i < test.n; i++) {
                for (int j = 0; j < test.m; j++) {
                    printf("%d ", test.arr[i][j]);
                }
                printf("\n");
            }
            for (int i = 0; i < test.n; i++) {
                for (int j = 0; j < test.m; j++) {
                    for (int z = 0; z < 100; z++) {
                        gif->frame[i * test.n * 100 + j + z] = test.arr[i][j].live;
                    }
                }
            }
            ge_add_frame(gif, 1);
        }
        ge_close_gif(gif);
    }
}