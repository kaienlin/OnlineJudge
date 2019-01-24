#include <stdio.h>

int main(void)
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

    if ( ax * by - ay * bx > 0 &&
         bx * cy - by * cx > 0 &&
         cx * dy - cy * dx > 0 &&
         dx * ay - dy * ax > 0) {
             printf("1");
         } else {
             printf("0");
         }
    return 0;
}