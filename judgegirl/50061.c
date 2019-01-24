#include <stdio.h>
#define MAXN 64

typedef unsigned long long ULL;

int N, money[MAXN], max;
ULL hate[MAXN];

void donation(int idx, int amount, ULL ban) {
	if ( amount > max )
		max = amount;
	if ( idx >= N )
		return;
	if ( !(ban & (1ULL << idx)) ) // remember that default integer type is 32-bit int, so add ULL postfix is necessary.
		donation(idx+1, amount + money[idx], ban | hate[idx]);
	donation(idx+1, amount, ban);
}

int main()
{
	scanf("%d", &N);
	for ( int i = 0; i < N; i++)
		scanf("%d", &money[i]);
	int h;
	for ( int i = 0; i < N; i++)
		for ( int j = 0; j < N; j++) {
			scanf("%d", &h);
			if ( h )
				hate[i] |= (1ULL << j);
		}
	donation(0, 0, 0ULL);
	printf("%d", max);
	return 0;
}

