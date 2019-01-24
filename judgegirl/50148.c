#include <stdio.h>
#define MAXN 100
#define swap(x, y) {int t = x; x = y; y = t;}
 
typedef struct rec {
    int w, l;
} Rec;
 
int fit(Rec t, Rec b) {
    #ifdef LARGEONSMALL
    return (b.w <= t.w && b.l <= t.l);
    #endif
    return (t.w <= b.w && t.l <= b.l);
}
 
int check(int sum, int max_area) {
    #ifdef MAXAREASUM
    return sum > max_area;
    #endif
    return max_area > sum;
}

int main()
{
    int N;
    scanf("%d", &N);
    Rec recs[MAXN];
    for ( int i = 0; i < N; i++) {
        scanf("%d%d", &recs[i].w, &recs[i].l);
        if ( recs[i].w > recs[i].l )
            swap(recs[i].w, recs[i].l);
    }
    int num[MAXN], area_sum[MAXN];
    int max_n = 0, max_area = 0;
    for ( int i = N - 1; i >= 0; i--) {
        int num_add = 0, area_add = 0;
        for ( int j = i + 1; j < N; j++)
            if ( fit(recs[j], recs[i]) )
                if ( num[j] > num_add || (num[j] == num_add && check(area_sum[j], area_add)) )
                    num_add = num[j], area_add = area_sum[j];
        num[i] = 1 + num_add;
        area_sum[i] = recs[i].w * recs[i].l + area_add;
        if ( num[i] > max_n || (num[i] == max_n && check(area_sum[i], area_add)) )
            max_n = num[i], max_area = area_sum[i];
    }
    printf("%d %d\n", max_n, max_area);
    return 0;
}