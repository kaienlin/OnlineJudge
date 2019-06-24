#include "RMQ.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;
const int MAXN = 1<<24;
const int MAXQ = 1<<24;
int main() {
	static int32_t A[MAXN];
	static int32_t Q[MAXQ][2];
	int n, m;
	assert(scanf("%d%d", &n, &m) == 2);
	for (int i = 0; i < n; i++)
		assert(scanf("%d", &A[i]) == 1);
	for (int i = 0; i < m; i++)
		assert(scanf("%d%d", &Q[i][0], &Q[i][1]) == 2);

	{
		int32_t *R = (int32_t *) malloc(sizeof(int32_t)*m);
		void *tool = preprocessing(n, A);
		offline_query(tool, m, Q, R);
		for (int i = 0; i < m; i++)
			printf("%d\n", R[i]);
		free(R);
		destroy(tool);
	}
	return 0;
}
