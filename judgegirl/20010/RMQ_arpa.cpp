#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define MAXN 10000000

using namespace std;

// DSU
int parent[MAXN], prv[MAXN], head[MAXN], L[MAXN];
int find_set(int v) {
    if ( parent[v] == -1 )
        return v;
    return (parent[v] = find_set(parent[v]));
}

struct Data {
    int N;
    int32_t *A;
    Data(int N, int32_t *A): N(N), A(A) {}
};

void* preprocessing(int N, int32_t A[]) {
    return new Data(N, A);
}

void offline_query(void *tool, int M, int32_t Q[][2], int32_t R[]) {
    Data *D = (Data*)tool;
    int32_t *A = D->A, n = D->N;
    memset(parent, -1, sizeof(parent));
    memset(head, -1, sizeof(head));
    for ( int i = 0; i < M; i++) {
        L[i] = Q[i][0];
        prv[i] = head[Q[i][1]], head[Q[i][1]] = i;
    }
    stack<int32_t> st;
    for ( int i = 0; i < n; i++) {
        while ( !st.empty() && A[st.top()] < A[i] ) {
            parent[st.top()] = i;
            st.pop();
        }
        st.push(i);
        for ( int q = head[i]; q >= 0; q = prv[q])
            R[q] = A[find_set(L[q])];
    }
}

void destroy(void *tool) {
}
