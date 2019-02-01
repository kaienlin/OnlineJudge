#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d", &q);
	while (q--) {
		int l1, r1, l2, r2;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		printf("%d %d\n", l1, r2 == l1 ? l2 : r2 );
	}
	return 0;
}
