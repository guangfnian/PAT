#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, maxn = 1100, maxm = 1100;
struct Edge {
	int u, v, cap, flow;
	Edge(int u, int v, int c, int f): u(u), v(v), cap(c), flow(f) {}
};

struct Dinic {
	int n, m, s, t;
	vector<Edge> egs;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn], cur[maxn];

	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; i++) G[i].clear();
		egs.clear();
		m = 0;
	}

	void addEdge(int u, int v, int cap) {
		egs.push_back(Edge(u, v, cap, 0));
		egs.push_back(Edge(v, u, 0, 0));
		m = egs.size();
		G[u].push_back(m-2);
		G[v].push_back(m-1);
	}

	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0, vis[s] = 1;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int i: G[x]) {
				Edge& e = egs[i];
				if(!vis[e.v] && e.cap > e.flow) {
					vis[e.v] = 1;
					d[e.v] = d[x] + 1;
					Q.push(e.v);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a) {
		if (x == t || a == 0) return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++) {
			Edge& e = egs[G[x][i]];
			if (d[x]+1 == d[e.v] && (f = DFS(e.v, min(a, e.cap-e.flow) ) ) > 0) {
				e.flow += f;
				egs[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
	}

	int Maxflow(int s, int t) {
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, inf);
		}
		return flow;
	}
} H;
map<string, int> mp;
int cnt = 2;
int main() {
	std::ios::sync_with_stdio(false);
	int n, c;
	string u, v;
	cin >> u >> v >> n;
	mp[u] = 1, mp[v] = 2;
	H.init(n*2+1);
	while (n--) {
		cin >> u >> v >> c;
		if (!mp[u]) {
			mp[u] = ++cnt;
		}
		if (!mp[v]) {
			mp[v] = ++cnt;
		}
		H.addEdge(mp[u], mp[v], c);
	}
	cout << H.Maxflow(1, 2) << endl;
	return 0;
}