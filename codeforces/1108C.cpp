#include <bits/stdc++.h>
#define MAXN 200001

using namespace std;

int main()
{
	int n;
	char s[MAXN] = "";
	cin >> n >> s;
	char p[6][4] = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};
	int min = 1 << 30, min_i;
	for ( int i = 0; i < 6; i++) {
		int cnt = 0;
		for ( int j = 0; j < n;)
			for ( int k = 0; k < 3 && j < n; k++, j++)
				if ( p[i][k] != s[j] ) 
					cnt++;
		if ( cnt < min ) 
			min = cnt, min_i = i;
	}
	cout << min << endl;
	for ( int i = 0; i < n; i++)
		cout << p[min_i][i % 3];
	cout << endl;
	return 0;
}
