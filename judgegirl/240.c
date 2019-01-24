/* 待優化: 1. 按逆時針排序可以用交換的方式 2. 可以用向量解決問題 */

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int i, j;
    int x[4], y[4];
    int cross12, cross13, cross23;
    int lenth[4];
    int cross_lenth[2];
    int all_right, all_equal;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d%d", &x[j], &y[j]);
        }
        all_equal = 0;
        all_right = 0;
        //calculating cross product: cross12---01 x 02, cross13---01 x 03, cross23---02 x 03
        //vector01 = (x[1] - x[0], y[1] - y[0]), vector02 = (x[2] - x[0], y[2] - y[0]), vector03 = (x[3] - x[0], y[3] - y[0])
        cross12 = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
        cross13 = (x[1] - x[0]) * (y[3] - y[0]) - (y[1] - y[0]) * (x[3] - x[0]);
        cross23 = (x[2] - x[0]) * (y[3] - y[0]) - (y[2] - y[0]) * (x[3] - x[0]);
        if (cross12 > 0 && cross13 > 0) {
            if (cross23 > 0) {
                //order = 0123
                //calculate four sides' lenth
                lenth[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
                lenth[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
                lenth[2] = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);
                lenth[3] = (x[3] - x[0]) * (x[3] - x[0]) + (y[3] - y[0]) * (y[3] - y[0]);
                cross_lenth[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
                cross_lenth[1] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);

                if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                    all_equal = 1;
                }
                if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                    lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                        all_right = 1;
                    }
            }
            else {
                //order = 0132
                lenth[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
                lenth[1] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
                lenth[2] = (x[3] - x[2]) * (x[3] - x[2]) + (y[3] - y[2]) * (y[3] - y[2]);
                lenth[3] = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
                cross_lenth[0] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
                cross_lenth[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);

                if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                    all_equal = 1;
                }
                if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                    lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                        all_right = 1;
                    }
            }     
        }
        else if (cross12 < 0 && cross13 < 0) {
            if (cross23 > 0) {
                //order = 0231
                lenth[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
                lenth[1] = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);
                lenth[2] = (x[3] - x[1]) * (x[3] - x[1]) + (y[3] - y[1]) * (y[3] - y[1]);
                lenth[3] = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
                cross_lenth[0] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
                cross_lenth[1] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);

                if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                    all_equal = 1;
                }
                if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                    lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                        all_right = 1;
                    }
            } else {
                //order = 0321
                lenth[0] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
                lenth[1] = (x[3] - x[2]) * (x[3] - x[2]) + (y[3] - y[2]) * (y[3] - y[2]);
                lenth[2] = (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]);
                lenth[3] = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
                cross_lenth[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
                cross_lenth[1] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);

                if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                    all_equal = 1;
                }
                if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                    lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                        all_right = 1;
                    }
            }
        }
        else if (cross12 > 0 && cross13 < 0) {
            //order = 0312
            lenth[0] = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
            lenth[1] = (x[3] - x[1]) * (x[3] - x[1]) + (y[3] - y[1]) * (y[3] - y[1]);
            lenth[2] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[1]) * (y[1] - y[1]);
            lenth[3] = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
            cross_lenth[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
            cross_lenth[1] = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);

            if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                all_equal = 1;
            }
            if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                    all_right = 1;
                }
            } else {
            //order = 0213
            lenth[0] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
            lenth[1] = (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]);
            lenth[2] = (x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3]);
            lenth[3] = (x[3] - x[0]) * (x[3] - x[0]) + (y[3] - y[0]) * (y[3] - y[0]);
            cross_lenth[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
            cross_lenth[1] = (x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3]);

            if (lenth[0] == lenth[1] && lenth[1] == lenth[2] && lenth[2] == lenth[3]) {
                all_equal = 1;
            }
            if (lenth[0] + lenth[1] == cross_lenth[0] && lenth[1] + lenth[2] == cross_lenth[1] &&
                lenth[2] + lenth[3] == cross_lenth[0] && lenth[3] + lenth[0] == cross_lenth[1]) {
                    all_right = 1;
                }
        }

        if (all_right && all_equal) {
            printf("square\n");
        } else if (all_right) {
            printf("rectangle\n");
        } else if (all_equal) {
            printf("diamond\n");
        } else {
            printf("other\n");
        }
    }
    return 0;
}
