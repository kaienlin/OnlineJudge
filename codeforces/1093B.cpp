#include <bits/stdc++.h>
#define MAXLEN 1024

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[MAXLEN];
		scanf("%s", str);
		auto len = strlen(str);
		sort(str, str + len);
		if ( str[0] == str[len-1] )
			puts("-1");
		else
			puts(str);
	}
	return 0;
}
