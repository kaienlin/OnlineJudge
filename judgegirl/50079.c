#include <stdio.h>

int main(void)
{
    int top, bottom;
    scanf("%d%d", &top, &bottom);
    printf("%d\n%d\n", ( top + bottom ) * ( bottom - top + 1 ) / 2, 3 * bottom - top - 2);
    return 0;
}
