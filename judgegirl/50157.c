#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a < b ? b : a; }
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

int main(void) {
    int k; scanf("%d", &k);
    int x, mx = -1, mx2 = -1, sum = 0, cnt[3] = {0};
    while ( ~scanf("%d", &x) ) {
        cnt[x % 3]++;
        if ( x > mx ) swap(&x, &mx);
        mx2 = max(x, mx2);
        if ( cnt[0] >= k && cnt[1] >= k && cnt[2] >= k ) {
            sum += mx2;
            mx = mx2 = -1;
            memset(cnt, 0, sizeof(cnt));
        }
    }
    if ( mx != -1 )
        sum += mx2 == -1 ? mx : mx2;
    printf("%d\n", sum);
}
