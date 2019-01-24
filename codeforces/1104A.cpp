#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	char out[1000] = "", *p = out;
	for ( int i = 9; i >= 1; i--) {
		if ( n % i == 0 ) {
			int a = n / i;
			memset(p, i + '0', a);
			p += a;
			cnt += a;
			n %= i;
		}
	}
	printf("%d\n", cnt);
	for ( int i = 0; i < cnt; i++)
		printf("%c%c", out[i], " \n"[i == cnt-1]);
	return 0;
}
