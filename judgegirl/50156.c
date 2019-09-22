#include <stdio.h>

int ans;
double mx;

void upd(int p, int d) {
    double v = (double)d / p;
    if ( v > mx )
        mx = v, ans = p;
}

int main()
{
    int a, b, v, w, mp[3];
    scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &mp[0], &mp[1], &mp[2]);
    ans = 1;
    upd(a, (a & 1) ? v : w);
    upd((a+1), ((a+1) & 1) ? v : w);
    upd(b, mp[b % 3]);
    upd(b+1, mp[(b+1) % 3]);
    upd(b+2, mp[(b+2) % 3]);
    printf("%d\n", ans);
}
