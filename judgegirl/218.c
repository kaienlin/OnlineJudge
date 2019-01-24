#include <stdio.h>

// test data may cause integer overflow
// still lots of optimization spaces: expecially the combination function
// there are ways to prevent integer overflow except using long long

long long factorial(int i)
{
    if ( i == 1 || i == 0 ) // 0! == 1
        return 1;
    else
        return i * factorial(i-1);
}

int C(int x, int y)
{
    if ( y == 0 ) 
        return 1;
    else    
        return (int)( factorial(x) / factorial(y) / factorial(x - y) );
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int sum = 0;
    for ( int i = 0; i <= m; i++) {
        sum += C(n, i);
    }
    printf("%d", sum);

    return 0;
}