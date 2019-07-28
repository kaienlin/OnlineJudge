#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define LOG2(x) (31-__builtin_clz(x))

using namespace std;

constexpr int Max_N = 1e7+5, Max_K = LOG2(Max_N)+1;

int st[Max_K][Max_N];

void* preprocessing(int N, int32_t A[]) {
    for ( int i = 0; i < N; i++)
        st[0][i] = A[i];
    for ( int j = 1; (1<<j) <= N; j++)
        for ( int i = 0; i + (1<<j) - 1 < N; i++)
            st[j][i] = max(st[j-1][i], st[j-1][i + (1<<(j-1))]);
    return nullptr;
}

void offline_query(void *tool, int M, int32_t Q[][2], int32_t R[]) {
    for ( int i = 0; i < M; i++) {
        int l = Q[i][0], r = Q[i][1];
        int j = LOG2(r - l + 1);
        R[i] = max(st[j][l], st[j][r - (1<<j) + 1]);
    }
}
 
void destroy(void *tool) {
}
