#include <stdio.h>

int maxvalue = 0;
int n;

void knapsack(int W, int index, int w[], int v[], int value)
{
    if ( W < 0 ) {
        return;
    } else if ( index >= n ) {
        maxvalue = value > maxvalue ? value : maxvalue; 
    } else {
        maxvalue = value > maxvalue ? value : maxvalue;
        knapsack(W - w[index], index + 1, w, v, value + v[index]);
        knapsack(W, index + 1, w, v, value);
    }
}

int main()
{
    int W;
    scanf("%d%d", &n, &W);
    int w[n], v[n];
    for ( int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    knapsack(W, 0, w, v, 0);
    printf("%d", maxvalue);
    return 0;
}