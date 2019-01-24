#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int l, r, g, n;
} Interval;

bool cmp(Interval a, Interval b) {
    if ( a.l != b.l ) return a.l < b.l;
    return a.r < b.r;
}

bool cmp2(Interval a, Interval b) {
    return a.n < b.n;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        Interval d[n];
        for ( int i = 0; i < n; i++) {
            scanf("%d %d", &d[i].l, &d[i].r);
            d[i].n = i;
        }
        sort(d, d + n, cmp);
        d[0].g = 1;
        bool f = false;
        int rr = d[0].r;
        for ( int i = 1; i < n; i++) {
            if ( d[i].l <= rr ) {
                d[i].g = d[i-1].g;
                rr = d[i].r > rr ? d[i].r : rr;
            } else {
                d[i].g = !d[i-1].g;
                rr = d[i].r;
                f = true;
            }
        }
        if ( f ) {
            sort(d, d + n, cmp2);
            for ( int i = 0; i < n; i++)
                printf("%c%c", d[i].g ? '1' : '2', " \n"[i == n-1]);
        } else {
            puts("-1");
        }
    }
}