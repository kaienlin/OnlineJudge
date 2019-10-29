#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int len, pref_len, start;
} Ans;

void upd(Ans *ans, int plen, int clen, int i) {
    int tot = plen + clen - 1;
    if ( tot > ans->len || (tot == ans->len && plen > ans->pref_len) ) {
        ans->len = tot;
        ans->pref_len = plen;
        ans->start = i - tot;
    }
}

int main()
{
    Ans ans = {0};
    int n, cur, prev, len = 2, plen = -1;
    bool inc;

    switch ( scanf("%d %d", &prev, &cur) ) {
        case 2:
            inc = cur > prev;
            prev = cur;
            break;
        default:
            puts("0");
            return 0;
    }
    for ( n = 3; ~scanf("%d", &cur); n++, prev = cur) {
        if ( cur > prev ) {
            if ( inc ) {
                len++;
            } else {
                inc = true;
                if ( plen != -1 )
                    upd(&ans, plen, len, n);
                plen = len;
                len = 2;
            }
        } else {
            if ( !inc ) {
                len++;
            } else {
                inc = false;
                if ( plen != -1 )
                    upd(&ans, plen, len, n);
                plen = len;
                len = 2;
            }
        }
    }
    if ( plen != -1 )
        upd(&ans, plen, len, n);

    if ( ans.len == 0 )
        puts("0");
    else
        printf("%d %d\n", ans.len, ans.start);
}
