//由片語學習c程式設計 p.118, hw. 6.10

#include <stdio.h>
#include <string.h>

void move(int*, int*, int);

int main(void)
{
    int w, d;
    int i, j, num = 0;
    
    scanf("%d%d", &w, &d);

    int room[d+2][w+2];
    memset(room, 0, sizeof room);

    for (i = 1; i <= w; i++, num++)
        room[d+1][i] = num;

    for (i = d; i >= 1; i--, num++)
        room[i][w+1] = num;

    for (i = w; i >= 1; i--, num++)
        room[0][i] = num;

    for (i = 1; i <= d; i++, num++)
        room[i][0] = num;

    for (i = 1; i < d+1; i++)
        for (j = 1; j < w+1; j++)
            scanf("%d", &room[i][j]);

/*    for (i = 0; i < d+2; i++) {
        for (j = 0; j < w+2; j++) 
            printf("%2d ", room[i][j]);
        printf("\n");
    }*/

    int x, y, dir;

    for (i = 1; i <= w; i++, num++) {
        y = d+1;
        x = i;
        dir = 1;
        for (j = 1; x < w+1 && y > 0; j++) {
            move(&x, &y, dir);
            if (room[y][x]) {
                if (dir == 1)
                    dir = 2;
                else if (dir == 2)
                    dir = 1;
            }
        }
        printf("%d\n", room[y][x]);
    }

    for (i = d; i >= 1; i--, num++) {
        y = i;
        x = w+1;
        dir = 4;
        for (j = 1; x > 0 && y < d+1; j++) {
            move(&x, &y, dir);
            if (room[y][x]) {
                if (dir == 4)
                    dir = 3;
                else if (dir == 3)
                    dir = 4;
            }
        }
        printf("%d\n", room[y][x]);
    }

    for (i = w; i >= 1; i--, num++) {
        y = 0;
        x = i;
        dir = 3;
        for (j = 1; x > 0 && y < d+1; j++) {
            move(&x, &y, dir);
            if (room[y][x]) {
                if (dir == 3)
                    dir = 4;
                else if (dir == 4)
                    dir = 3;
            }
        }
        printf("%d\n", room[y][x]);
    }


    for (i = 1; i <= d; i++, num++) {
        y = i;
        x = 0;
        dir = 2;
        for (j = 1; x < w+1 && y > 0; j++) {
            move(&x, &y, dir);
            if (room[y][x]) {
                if (dir == 1)
                    dir = 2;
                else if (dir == 2)
                    dir = 1;
            }
        }
        printf("%d\n", room[y][x]);
    }

    return 0;
}

void move(int* x, int* y, int dir)
{
    switch (dir)
    {
        case 1:
            (*y)--;
            break;
        case 2:
            (*x)++;
            break;
        case 3:
            (*y)++;
            break;
        case 4:
            (*x)--;
            break;
    }
}
