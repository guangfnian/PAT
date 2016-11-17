#include <bits/stdc++.h>
using namespace std;
const int N = 550, inf = 0x3f3f3f3f;
struct edge {
	int nxt, l, t;
	edge(int a, int b, int c): nxt(a), l(b), t(c){}
};
vector<edge> e[N];
int tim[2][N], dis[2][N], vis[N], n;
void spfa(int x, int k) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(x);
	tim[k][x] = 0;
	dis[k][x] = 0;
	vis[x] = 1;
	if (!k) {
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto &i: e[t]) {
				if (dis[k][t] + i.l < dis[k][i.nxt]) {
					dis[k][i.nxt] = dis[k][t] + i.l;
					tim[k][i.nxt] = tim[k][t] + i.t;
					if (!vis[i.nxt]) {
						vis[i.nxt] = 1;
						q.push(i.nxt);
					}
				} else if (dis[k][t] + i.l == dis[k][i.nxt] && tim[k][t] + i.t < tim[k][i.nxt]) {
					tim[k][i.nxt] = tim[k][t] + i.t;
					if (!vis[i.nxt]) {
						vis[i.nxt] = 1;
						q.push(i.nxt);
					}
				}
			}
			vis[t] = 0;
		}
	} else {
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto &i: e[t]) {
				if (tim[k][t] + i.t < tim[k][i.nxt]) {
					dis[k][i.nxt] = dis[k][t] + 1;
					tim[k][i.nxt] = tim[k][t] + i.t;
					if (!vis[i.nxt]) {
						vis[i.nxt] = 1;
						q.push(i.nxt);
					}
				} else if (tim[k][t] + i.t == tim[k][i.nxt] && dis[k][t] + 1 < dis[k][i.nxt]) {
					dis[k][i.nxt] = dis[k][t] + 1;
					if (!vis[i.nxt]) {
						vis[i.nxt] = 1;
						q.push(i.nxt);
					}
				}
			}
			vis[t] = 0;
		}
	}
}
bool dfs(int p, int ed, int k, vector<int> &ans) {
	if (p == ed) {
		ans.push_back(p);
		return 1;
	}
	for (auto &i: e[p]) {
		if (dis[k][p] + (k?1: i.l) == dis[k][i.nxt] && tim[k][p] + i.t == tim[k][i.nxt] && dfs(i.nxt, ed, k, ans)) {
			ans.push_back(p);
			return 1;
		}
	}
	return 0;
}
int main() {
	int m, u, v, k, l, t, st, ed;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d%d%d", &u, &v, &k, &l, &t);
		e[u].push_back(edge(v, l, t));
		if (!k) {
			e[v].push_back(edge(u, l, t));
		}
	}
	scanf("%d%d", &st, &ed);
	fill(&dis[0][0], &dis[0][0] + sizeof(dis)/sizeof(dis[0][0]), inf);
	fill(&tim[0][0], &tim[0][0] + sizeof(tim)/sizeof(tim[0][0]), inf);
	spfa(st, 0);
	spfa(st, 1);
	vector<int> ans1, ans2;
	dfs(st, ed, 0, ans1);
	dfs(st, ed, 1, ans2);
	reverse(ans1.begin(), ans1.end());
	reverse(ans2.begin(), ans2.end());
	if (ans1 != ans2) {
		printf("Distance = %d: %d", dis[0][ed], st);
		for (int i = 1; i < ans1.size(); i++) {
			printf(" -> %d", ans1[i]);
		}
		puts("");
		printf("Time = %d: %d", tim[1][ed], st);
		for (int i = 1; i < ans2.size(); i++) {
			printf(" -> %d", ans2[i]);
		}
		puts("");
	} else {
		printf("Distance = %d; Time = %d: %d", dis[0][ed], tim[1][ed], st);
		for (int i = 1; i < ans1.size(); i++) {
			printf(" -> %d", ans1[i]);
		}
		puts("");
	}
	return 0;
}

