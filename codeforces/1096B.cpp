#include <bits/stdc++.h>
#define ANSMOD 998244353ULL
#define MAXN 200001

using namespace std;

typedef struct {
	char c = '\0';
	unsigned long long len = 0;
} Seg;

int main()
{
	int n;
	scanf("%d", &n);
	char str[MAXN];
	scanf("%s", str);
	Seg pre, suf;
	pre.c = str[0], suf.c = str[n-1];
	for ( pre.len = 0; pre.len < n && str[pre.len] == pre.c; pre.len++);
	for ( suf.len = 0; suf.len >= 0 && str[n - suf.len - 1] == suf.c; suf.len++);
	if ( pre.c == suf.c ) {
		printf("%llu\n", (static_cast<unsigned long long>(pre.len) + 1) * (suf.len + 1) % ANSMOD );	
	} else {
		printf("%llu\n", (pre.len + suf.len + 1) % ANSMOD );
	}
	return 0;
}
