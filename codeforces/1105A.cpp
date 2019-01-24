#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int main()
{
	int n;
	unsigned short a[MAXN];
	scanf("%d", &n);
	for ( int i = 0; i < n; i++)
		scanf("%hu", &a[i]);
	unsigned min_cost = 1 << 31, min_t;
	for ( int i = 1; i <= 100; i++) {
		int cost = 0;
		for ( int j = 0; j < n; j++)
			cost += abs(i - a[j]) + (abs(i - a[j]) == 0 ? 0 : -1);
		if ( cost < min_cost )
			min_cost = cost, min_t = i;
	}
	printf("%d %d\n", min_t, min_cost);
	return 0;
}
