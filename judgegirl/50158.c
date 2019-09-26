#include <stdio.h>
#include <string.h>
#define swap(a, b) {(a) ^= (b) ^= (a) ^= (b);}

int a, b, c, d, e;
int C(int x) {
    int ans = 0;
    for ( ; x < d || x > e; ans++)
        x = (a * x + b) % c;
    return ans;
}
void shift(int v[]) {
    v[0] = v[1]; v[1] = v[2];
}
void sort(int A[]) {
    for ( int i = 0; i < 2; i++)
        for ( int j = 0; j < 2-i; j++)
            if ( A[j] > A[j+1] )
                swap(A[j], A[j+1]); 
}

int main(void)
{
    int x, v[3], f[3] = {-9, -1, -120};
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    while ( ~scanf("%d", &x) ) {
        shift(v); v[2] = x;
        shift(f); f[2] = C(x);
        int tmp[3]; memcpy(tmp, f, sizeof(f));
        sort(tmp);
        if ( tmp[0] + 1 == tmp[1] && tmp[1] + 1 == tmp[2] ) {
            printf("%d %d %d\n", v[0], v[1], v[2]);
            return 0;
        }
    }
    puts("Not found");
}
