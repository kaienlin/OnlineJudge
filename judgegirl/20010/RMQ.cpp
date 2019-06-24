#include <bits/stdc++.h>

using namespace std;

struct SparseTable {
	int R, C;
	int32_t **table;
	int32_t *log_two, *pow_two;
	SparseTable(int N): R(N), C(int(log2(N))+1) {
		table = new int32_t*[N];
		for ( int i = 0; i < N; i++)
			table[i] = new int32_t[C];
		log_two = new int32_t[N+1];
		for ( int i = 1; i <= N; i++)
			log_two[i] = (int32_t)log2(i);
		pow_two = new int32_t[C+1];
		for ( int i = 0; i <= C; i++)
			pow_two[i] = 1 << i;
	}
};

void* preprocessing(int N, int32_t A[]) {
	SparseTable *ret = new SparseTable(N);
	for ( int i = 0; i < N; i++)
		ret->table[i][0] = A[i];
	for ( int j = 1; j < ret->C; j++) {
		for ( int i = 0; i + ret->pow_two[j] - 1 < N; i++) {
			if ( ret->table[i][j-1] > ret->table[i + ret->pow_two[j-1]][j-1] )
				ret->table[i][j] = ret->table[i][j-1];
			else
				ret->table[i][j] = ret->table[i + ret->pow_two[j-1]][j-1];
		}
	}
	return ret;
}

void offline_query(void *tool, int M, int32_t Q[][2], int32_t R[]) {
	SparseTable *t = (SparseTable*)tool;
	for ( int i = 0; i < M; i++) {
		int32_t l = Q[i][0], r = Q[i][1];
		int32_t j = t->log_two[r - l + 1];
		if ( t->table[l][j] >= t->table[r - t->pow_two[j] + 1][j] )
			R[i] = t->table[l][j];
		else
			R[i] = t->table[r - t->pow_two[j] + 1][j];
	}
}

void destroy(void *tool) {
}
