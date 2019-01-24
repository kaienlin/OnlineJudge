#include <stdio.h>

// I may not really understand this problem, think it more.
// When object is on top or right edge, it don't have choice anymore. ---> it only have one choice

int ways(int r, int c)
{
    if ( r == 1 || c == 1 ) {
        return 1;
    } else {
        return ways(r - 1, c) + ways(r, c - 1);
    }
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d", ways(r, c));
    return 0;
}