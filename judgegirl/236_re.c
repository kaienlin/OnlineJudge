#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

int gcd(int a, int b) {
    while ( b ) {
        a %= b;
        swap(&a, &b);
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main()
{
    int ans = 1, x;
    while ( ~scanf("%d", &x) )
        ans = lcm(ans, x);
    printf("%d\n", ans);
    return 0;
}
