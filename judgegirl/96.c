#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double area = 0.0;

    if ( c > a ) {
        area += (c - a) * (c - a) * 0.25;
    }
    if ( c > b ) {
        area += (c - b) * (c - b) * 0.25;
    }
    area += c * c * 0.75;
    area *= 3.1415926;
    printf("%6f", area);
    return 0;
}