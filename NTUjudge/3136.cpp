#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }

using namespace std;

const int max_n = 30, max_q = 30, max_s = 100;

#define SZ(x) ((int)(x).size())

struct Dinic_Flow {
	static const int MAX_N = 8e3 + 6;
	static const int INF = 1e9 +7;
	int n,s,t;
	struct Edge {
		int to,cap,rev;
	};
	vector<Edge> edg[MAX_N];
	void init(int _n,int _s,int _t) {
		for (int i=0;_n>=i;i++) {
			edg[i].clear();
		}
		n=_n;
		s=_s;
		t=_t;
	}
	void add_edge(int from,int to,int cap) {
		edg[from].push_back({to,cap,SZ(edg[to])});
		edg[to].push_back({from,0,SZ(edg[from])-1});
	}
	int level[MAX_N],iter[MAX_N];
	void bfs(int s) {
		queue<int> que;
		que.push(s);
		memset(level,-1,sizeof(level));
		level[s] = 0;
		while (!que.empty()) {
			int t=que.front();
			que.pop();
			for (Edge e:edg[t]) {
				if (e.cap > 0 && level[e.to]==-1) {
					level[e.to] = level[t] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int id,int flow) {
		if (id==t) return flow;
		int ret=0;
		for (int &i=iter[id];SZ(edg[id])>i;i++) {
			Edge &e=edg[id][i];
			if (e.cap > 0 && level[e.to] == level[id] + 1) {
				int ret=dfs(e.to,min(flow,e.cap));
				if (ret>0) {
					e.cap -= ret;
					edg[e.to][e.rev].cap += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	int mxflow() {
		int ret=0;
		while(true) {
			bfs(s);
			if (level[t] == -1) return ret;
			int tmp=0;
			memset(iter,0,sizeof(iter));
			while ((tmp=dfs(s,INF)) > 0) {
				ret += tmp;
			}
		}
		return ret;
	}
} flow;


int n, q, s;
int sq_mp[max_s+1], que_sz[max_q+1];
int qa[max_n+1][max_q+1], qb[max_n+1][max_q+1];
int qs[max_q+1];

int main()
{
    IOS;
    cin >> n >> q >> s;
    for ( int i = 1; i <= s; i++)
        cin >> sq_mp[i];
    for ( int i = 1; i <= q; i++)
        cin >> que_sz[i];

    int nd = n + 1;
    for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= q; j++) {
            qa[i][j] = nd++;
            qb[i][j] = nd++;
        }
    }

    int src = 0, sink = nd;
    flow.init(sink+1, src, sink);

    for ( int wn = 1; wn <= n; wn++) {
        for ( int qn = 1; qn <= q; qn++) {
            flow.add_edge(qa[wn][qn], qb[wn][qn], que_sz[qn]);
            flow.add_edge(qb[wn][qn], wn, flow.INF);
        }
    }

    for ( int wn = 1; wn < n; wn++) {
        for ( int qn = 1; qn <= q; qn++) {
            flow.add_edge(qb[wn][qn], qa[wn+1][qn], flow.INF);
        }
    }

    int expect = 0;
    for ( int wn = 1; wn <= n; wn++) {
        int d; cin >> d;
        flow.add_edge(wn, sink, d);
        memset(qs, 0, sizeof(qs));
        for ( int sn = 1; sn <= s; sn++) {
            int a; cin >> a;
            expect += a;
            qs[sq_mp[sn]] += a;
        }
        for ( int qn = 1; qn <= q; qn++)
            if ( qs[qn] )
                flow.add_edge(src, qa[wn][qn], qs[qn]);
    }

    if ( flow.mxflow() < expect )
        cout << "impossible\n";
    else
        cout << "possible\n";
    return 0;
}
