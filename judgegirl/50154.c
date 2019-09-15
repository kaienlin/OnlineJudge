#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int edges = (a + b + c + d) + ((a + b + c) * e + (c + d) * f) +
                (e * g) + g + f;
    int paths = (a + b + c) * e * g + (c + d) * f;
    printf("%d\n%d\n", edges, paths);
    return 0;
}
