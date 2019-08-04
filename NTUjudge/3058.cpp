#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

bool used[4][14];

int F[128];

void init() {
    for ( int i = 2; i <= 9; i++) F['0' + i] = i;
    F['A'] = 1; F['T'] = 10; F['J'] = 11; F['Q'] = 12; F['K'] = 13;
    F['S'] = 0; F['H'] = 1; F['D'] = 2; F['C'] = 3;
}

struct CardSet
{
    bool has[4][15];  // A: 1, 14
    CardSet() { memset(has, 0, sizeof(has)); }
    CardSet(pii cards[]) {
        memset(has, 0, sizeof(has));
        for ( int i = 0; i < 7; i++) {
            has[ cards[i].fi ][ cards[i].se ] = true;
            if ( cards[i].se == 1 ) has[ cards[i].fi ][14] = true;
        }
    }
    pii is_royal_straight_flush() {
        for ( int su = 0; su <= 3; su++)
            if ( has[su][14] && has[su][13] && has[su][12] && has[su][11] && has[su][10] )
                return pii(9, 0);
        return pii(-1, -1);
    }
    pii is_straight_flush() {
        pii ret(-1, -1);
        for ( int su = 0; su <= 3; su++) {
            for ( int top = 14 - 1; top >= 5; top--) {
                bool yes = true;
                for ( int t = top; t >= top - 4; t--)
                    if ( !has[su][t] )
                        yes = false;
                if ( yes ) {
                    ret = max(ret, pii(8, top));
                    break;
                }
            }
        }
        return ret;
    }
    pii is_four_of_kind() {
        for ( int rk = 14; rk >= 2; rk--) {
            if ( has[0][rk] && has[1][rk] && has[2][rk] && has[3][rk] ) {
                for ( int t = 14; t >= 2; t--)
                    if ( t != rk && (has[0][t] || has[1][t] || has[2][t] || has[3][t]) )
                        return pii(7, (rk << 4) + t);
            }
        }
        return pii(-1, -1);
    }
    pii is_full_house() {
        for ( int rk = 14; rk >= 2; rk--) {
            int cnt = has[0][rk] + has[1][rk] + has[2][rk] + has[3][rk];
            if ( cnt >= 3 ) {
                for ( int t = 14; t >= 2; t--) {
                    int num = has[0][t] + has[1][t] + has[2][t] + has[3][t];
                    if ( t != rk && num >= 2 )
                        return pii(6, (rk << 4) + t);
                }
            }
        }
        return pii(-1, -1);
    }
    pii is_flush() {
        pii ret(-1, -1);
        for ( int su = 0; su <= 3; su++) {
            int v = 0;
            for ( int rk = 14, n = 0; rk >= 2; rk--) {
                if ( has[su][rk] ) {
                    v = (v << 4) + rk;
                    if ( (++n) == 5 ) {
                        ret = max(ret, pii(5, v));
                        break;
                    }
                }
            }
        }
        return ret;
    }
    pii is_straight() {
        for ( int top = 14; top >= 5; top--) {
            bool yes = true;
            for ( int t = top; t >= top - 4; t--)
                if ( !(has[0][t] || has[1][t] || has[2][t] || has[3][t]) )
                    yes = false;
            if ( yes ) {
                return pii(4, top);
            }
        }
        return pii(-1, -1);
    }
    pii is_three_of_a_kind() {
        for ( int rk = 14; rk >= 2; rk--) {
            int cnt = has[0][rk] + has[1][rk] + has[2][rk] + has[3][rk];
            if ( cnt >= 3 ) {
                pii ret(3, rk);
                for ( int t = 14, n = 0; t >= 2 && n < 2; t--) {
                    if ( t != rk && (has[0][t] || has[1][t] || has[2][t] || has[3][t] ) ) {
                        ret.se = (ret.se << 4) + t;
                        n++;
                    }
                }
                return ret;
            }
        }
        return pii(-1, -1);
    }
    pii is_two_pairs() {
        int prev[2];
        pii ret(2, 0);
        for ( int rk = 14, n = 0; rk >= 2; rk--) {
            int cnt = has[0][rk] + has[1][rk] + has[2][rk] + has[3][rk];
            if ( cnt >= 2 ) {
                prev[n++] = rk;
                ret.se = (ret.se << 4) + rk;
            }
            if ( n == 2 ) {
                for ( int t = 14; t >= 2; t--) {
                    if ( t != prev[0] && t != prev[1] && (has[0][t] || has[1][t] || has[2][t] || has[3][t]) ) {
                        ret.se = (ret.se << 4) + t;
                        return ret;
                    }
                }
            } 
        }
        return pii(-1, -1);
    }
    pii is_one_pair() {
        for ( int rk = 14; rk >= 2; rk--) {
            int cnt = has[0][rk] + has[1][rk] + has[2][rk] + has[3][rk];
            if ( cnt >= 2 ) {
                pii ret(1, rk);
                for ( int t = 14, n = 0; t >= 2; t--) {
                    if ( t != rk && (has[0][t] || has[1][t] || has[2][t] || has[3][t]) ) {
                        ret.se = (ret.se << 4) + t;
                        if ( (++n) == 3 )
                            return ret;
                    }
                }
            }
        }
        return pii(-1, -1);
    }
    pii get_high_card() {
        pii ret(0, 0);
        for ( int rk = 14, n = 0; rk >= 2; rk--) {
            if ( has[0][rk] || has[1][rk] || has[2][rk] || has[3][rk] ) {
                ret.se = (ret.se << 4) + rk;
                if ( (++n) == 5 )
                    return ret;
            }
        }
    }
    pii calc() {
        pii result(-1, -1), notyet(-1, -1);
        result = is_royal_straight_flush(); if ( result != notyet ) return result;
        result = is_straight_flush(); if ( result != notyet ) return result;
        result = is_four_of_kind(); if ( result != notyet ) return result;
        result = is_full_house(); if ( result != notyet ) return result;
        result = is_flush(); if ( result != notyet ) return result;
        result = is_straight(); if ( result != notyet ) return result;
        result = is_three_of_a_kind(); if ( result != notyet ) return result;
        result = is_two_pairs(); if ( result != notyet ) return result;
        result = is_one_pair(); if ( result != notyet ) return result;
        return get_high_card();
    } 
};

void prepare() {
    memset(used, 0, sizeof(used));
}
void convert(pii & target, string s) {
    target.fi = F[ s[0] ];
    target.se = F[ s[1] ];
}
void set_used(pii my[], pii riv[], pii com[]) {
    for ( int i = 0; i < 2; i++)
        used[ my[i].fi ][ my[i].se ] = true;
    for ( int i = 0; i < 2; i++)
        used[ riv[i].fi ][ riv[i].se ] = true;
    for ( int i = 0; i < 3; i++)
        used[ com[i].fi ][ com[i].se ] = true;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    init();
    while ( true ) {
        prepare();
        string s; cin >> s;
        if ( s == "#" ) break;
        pii my[7], riv[7], com[3];
        convert(my[0], s);
        cin >> s; convert(my[1], s);
        cin >> s; convert(riv[0], s);
        cin >> s; convert(riv[1], s);
        cin >> s; convert(com[0], s);
        cin >> s; convert(com[1], s);
        cin >> s; convert(com[2], s);

        for ( int i = 0; i < 3; i++) {
            my[i+2] = com[i];
            riv[i+2] = com[i];
        }

        set_used(my, riv, com);

        int win = 0, lost = 0;
        for ( int su1 = 0; su1 < 4; su1++) {
            for ( int rk1 = 1; rk1 <= 13; rk1++) {
                for ( int su2 = 0; su2 < 4; su2++) {
                    for ( int rk2 = 1; rk2 <= 13; rk2++) {
                        if ( used[su1][rk1] || used[su2][rk2] || (su1 == su2 && rk1 == rk2) ) continue;
                        my[5] = riv[5] = {su1, rk1};
                        my[6] = riv[6] = {su2, rk2};
                        CardSet my_s(my);
                        CardSet riv_s(riv);
                        if ( my_s.calc() > riv_s.calc() )
                            win++;
                        else
                            lost++;
                    }
                }
            }
        }
        if ( lost == 0 )
            cout << "1.00000000000000000000\n";
        else
            cout << setprecision(20) << (double)win / ((double)win + lost) << '\n';
    }
}
