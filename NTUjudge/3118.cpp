#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;
using LL = int64_t;

const size_t MAXN = (1<<20);
const LL mod = 7340033, G = 5;
LL invG;

LL pp[mod], inv[mod];

void init() {
    inv[1] = 1;
    for ( int i = 2; i < mod; i++)
        inv[i] = ((LL)mod - (mod / i) * inv[mod % i] % mod) % mod;
    invG = inv[G];
    fill(pp, pp+mod, -1LL);
    for ( LL i = mod-1; i >= 0; i--)
        pp[i * i % mod] = i;
}
LL fpow(LL a, LL n){
    LL ans = 1LL;
    for (; n; n >>= 1) {
        if ( n & 1 ) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
void FFT(LL a[], int n, bool invert=false){
    for ( int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for ( ; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if ( i < j )
            swap(a[i], a[j]);
    }    
    for (int i = 1; i < n; i <<= 1){
        LL wn = fpow(invert ? invG : G, (mod-1)/i/2);
        for (int j = 0; j < n; j += i*2){
            LL w = 1;
            for ( int k = 0; k < i; k++){
                LL x = a[j+k], y = a[i+j+k] * w % mod;
                a[j+k] = (x+y) % mod;
                a[i+j+k] = (x - y + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if ( invert ) {
        LL invn = inv[n];
        for (int i=0;i<n;i++)
            a[i] = a[i] * invn % mod;
    }
}
void poly_mul(LL A[], LL B[], int n){
    int N = 1 << (32-__builtin_clz(n));
    FFT(A, N, false);
    FFT(B, N, false);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % mod;
    FFT(A, N, true);
    fill(A+n, A+N, 0);
}
void poly_cal(LL A[],LL B[],int n){
    int N = 1 << (32-__builtin_clz(n));
    FFT(A, N, false);
    FFT(B, N, false);
    for (int i = 0; i < N;i++)
        B[i] = B[i] * (2 - A[i] * B[i] % mod + mod) % mod;
    FFT(B, N, true);
    fill(B+n, B+N, 0);
}

LL tmp[MAXN];

void poly_inv(LL A[], LL ans[], int n) {
    if ( n == 1 ) {
        ans[0] = inv[A[0]];
        return;
    }
    poly_inv(A, ans, (n+1)/2);
    memset(tmp, 0, sizeof(tmp));
    copy(A, A+n, tmp);
    poly_cal(tmp, ans, n);
}

LL C[MAXN],B[MAXN],D[MAXN];

void poly_sqrt(LL A[], LL ans[], int n){
    if ( n == 1 ) {
        ans[0] = pp[A[0]];
        return;
    }
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(D, 0, sizeof(D));
    poly_sqrt(A, ans, (n+1)/2);
    for (int i = 0; i < n; i++){
        C[i] = ans[i] * 2 % mod;
        D[i] = ans[i];
        B[i] = 0;
    }
    poly_inv(C, B, n);
    poly_mul(ans, D, n);
    for (int i = 0; i < n;i++)
        ans[i] = (ans[i] + A[i]) % mod;
    poly_mul(ans, B, n);
}

LL A[MAXN], ans[MAXN];

int main(){
    IOS;
    init();
    int N; cin >> N; ++N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int zero = 0;
    for ( ; zero < N && A[zero] == 0; zero++);
    if ( zero == N ) {
        for ( int i = 0; i < N; i++)
            cout << "0" << " \n"[i==N-1];
        return 0;
    } else if ( zero & 1 ) {
        for ( int i = 0; i < N; i++)
            cout << "-1" << " \n"[i == N-1];
        return 0;
    } else {
        memmove(A, A + zero, sizeof(LL) * (MAXN-zero));
        N -= zero;
        fill(A+N+1, A+MAXN, 0);
    }
    int nxt2k = 1 << (32-__builtin_clz(N));
    if ( pp[A[0]] != -1 ) {
        poly_sqrt(A, ans, nxt2k);
        bool f = true;
        for ( int i = 0; i < zero/2; i++) {
            if ( f ) { cout << "0"; f = false; }
            else { cout << " 0"; }
        }
        for ( int i = 0; i < N; i++) {
            if ( f ) { cout << ans[i]; f = false; }
            else { cout << " " << ans[i]; }
        }
        for ( int i = 0; i < zero/2; i++)
            cout << " 0";
        cout << '\n';
    } else {
        N += zero;
        for ( int i = 0; i < N; i++)
            cout << "-1" << " \n"[i == N-1];
    }
    return 0;
}
