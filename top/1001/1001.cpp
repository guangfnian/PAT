#include <bits/stdc++.h>
using namespace std;
const int N = 550, INF = 0x3f3f3f3f;
int fa[N];
struct edge {
	int u, v, l;
	edge(int u = 0, int v = 0, int l = 0): u(u), v(v), l(l){}
	friend bool operator < (edge a, edge b) {
		return a.l < b.l;
	}
};
int Find(int x) {
	return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}
void combine(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y) {
		fa[x] = y;
	}
}
vector<edge> e, d;
int main() {
	int n, m, u, v, l, p;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d%d", &u, &v, &l, &p);
		if (p) {
			e.push_back(edge(u, v, l));
		} else {
			d.push_back(edge(u, v, l));
		}
	}
	sort(d.begin(), d.end());
	int mx = 0, f = 0;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			fa[j] = j;
		}
		for (auto j: e) {
			if (j.u == i || j.v == i) {
				continue;
			}
			combine(j.u, j.v);
		}
		for (auto j: d) {
			if (j.u == i || j.v == i) {
				continue;
			}
			int x = Find(j.u), y = Find(j.v);
			if (x != y) {
				fa[x] = y;
				f = 1;
				cnt += j.l;
			}
		}
		int c = 0;
		for (int j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			c += (j == fa[j]);
		}
		if (c > 1) {
			cnt = INF;
		}
		if (cnt > mx) {
			mx = cnt;
			ans.clear();
			ans.push_back(i);
		} else if (cnt == mx) {
			ans.push_back(i);
		}
	}
	if (!f) {
		puts("0");
	} else {
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}