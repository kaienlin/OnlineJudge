#include <stdio.h>

// check if match condition when process through the whole array

int pickup(int k, int N, int M, int set[], int index)
{
    if ( M < 0 )
        return 0;
    if ( index == N && k <= 0 && M >= 0 )
        return 1;
    if ( index == N )
        return 0;
    return pickup(k - 1, N, M - set[index], set, index + 1) + pickup(k, N, M, set, index + 1);
}

int main()
{
    int k, N, M;
    scanf("%d%d%d", &k, &N, &M);
    int set[20];
    for ( int i = 0; i < N; i++)
        scanf("%d", &set[i]);
    printf("%d", pickup(k, N, M, set, 0));
    return 0;
}