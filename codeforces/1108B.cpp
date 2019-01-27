#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	list<int> d(n);
	int max = 0;
	for ( auto i = d.begin(); i != d.end(); i++) {
		cin >> *i;
		max = *i > max ? *i : max;
	}
	cout << max << " ";
	array<bool, 10001> visited{0};
	for ( auto i = d.begin(); i != d.end(); ) {
		if ( max % *i == 0 && visited[*i] == false ) {
			visited[*i] = true;
			i = d.erase(i);
		} else
			i++;
	}
	max = 0;
	for ( auto i = d.begin(); i != d.end(); i++)
		max = *i > max ? *i : max;
	cout << max << endl;
	return 0;
}
