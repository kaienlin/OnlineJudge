#include <stdio.h>

int f(int x);
int h(int y);
int g(int z);

int f(int x)
{
    if ( x > h(x) ) {
        return f(x - 1) - h(x);
    } else if ( x < h(x) ) {
        return f(g(x)) - g(x);
    } else {
        return 1;
    }
}

int h(int y)
{
    if ( y < 2 ) {
        return -1;
    } else {
        return 2 + h(y - 1) - h(y - 2);
    }
}

int g(int z)
{
    if ( z <= 2 ) {
        return z * z - 1;
    } else {
        return 2;
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}