#include <bits/stdc++.h>

using namespace std;

// Bron-Kerbosch Algorithm for maximum clique problem
// recursive backtracking

struct MaximumClique {
	static constexpr int MAXN = 50+5;
	typedef bitset<MAXN> bst;
	bst G[MAXN], empty;
	int n, ans;
	void init(int _n) {
		n = _n;
		for ( int i = 0; i < MAXN; i++)
			G[i].reset();
	}
	void add_edge(int a,int b) {
		G[a][b] = G[b][a] = 1;
	}
	void BronKerbosch(bst R, bst P, bst X) {
        // R: current clique
        // P: to visit
        // X: NOT in clique
		if ( P == empty && X == empty ) {  // no elements that can be added to R
			ans = max(ans,(int)R.count());
			return;
		} else if ( (R | P | X).count() <= ans ) // pruning
            return;
        // P union X is the set of vertices which are joined to every element of R
        // choose a pivot vertex "u" from P U X
		int u = (P | X)._Find_first();
		bst now = P & (~G[u]);  // P - G[u]
        // test u and its non-neighbors
		for (int v = 0; v < n; v++) {
			if ( now[v] ) {
				R[v] = 1;
				BronKerbosch(R, P & G[v], X & G[v]);
				R[v] = 0; P[v] = 0; X[v] = 1;
			}
		}
	}
	int solve() {
		ans = 0;
		bst R, P, X;  // disjoint set of vertices
        // R, X: empty set, P: all vertex set
		P.set();
		BronKerbosch(R, P, X);
		return ans;
	}
} solver;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;
    while ( cin >> N && N ) {
        solver.init(N);
        for ( int i = 0; i < N; i++) {
            for ( int j = 0; j < N; j++) {
                int x; cin >> x;
                if ( x ) solver.add_edge(i, j);
            }
        }
        cout << solver.solve() << '\n';
    }
}
