#include <bits/stdc++.h>
using namespace std;
const int N = 220, inf = 0x3f3f3f3f;
struct edge {
	int to, l;
	edge(int t, int l): to(t), l(l){}
};
int dis[N], cnt[N], val[N], happy[N], n, ed;
int vis[N];
vector<edge> e[N];
map<string, int> mp;
vector<string> city;
void spfa() {
	fill(dis, dis+n+5, inf);
	fill(cnt, cnt+n+5, inf);
	fill(happy, happy+n+5, -inf);
	memset(vis, 0, sizeof(vis));
	queue<int> que;
	que.push(0);
	vis[0] = 1;
	dis[0] = 0;
	cnt[0] = 0;
	happy[0] = 0;
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		if (t == ed) {
			continue;
		}
		for (auto i: e[t]) {
			if (dis[t] + i.l < dis[i.to]) {
				dis[i.to] = dis[t] + i.l;
				cnt[i.to] = cnt[t] + 1;
				happy[i.to] = happy[t] + val[i.to];
				if (!vis[i.to]) {
					que.push(i.to);
				}
				vis[i.to] = vis[t];
			} else if (dis[t] + i.l == dis[i.to]) {
				if (happy[t] + val[i.to] > happy[i.to]) {
					happy[i.to] = happy[t] + val[i.to];
					cnt[i.to] = cnt[t] + 1;
					if (!vis[i.to]) {
						que.push(i.to);
					}
				} else if (happy[t] + val[i.to] == happy[i.to] && cnt[t] + 1 < cnt[i.to]) {
					cnt[i.to] = cnt[t] + 1;
					if (!vis[i.to]) {
						que.push(i.to);
					}
				}
				vis[i.to] += vis[t];
			}
		}
		vis[t] = 0;
	}
}
void dfs(int p, vector<string> &ans) {
	if (p == 0) {
		return;
	}
	for (auto i: e[p]) {
		if (dis[p] == dis[i.to] + i.l && cnt[p] == cnt[i.to] + 1 && happy[p] == happy[i.to] + val[p]) {
			dfs(i.to, ans);
		}
	}
	ans.push_back(city[p]);
}
int main() {
    std::ios::sync_with_stdio(false);
    int m, t;
    string x, y;
    cin >> n >> m >> x;
    mp[x] = 0;
    city.push_back(x);
    for (int i = 1; i < n; i++) {
    	cin >> x >> t;
    	mp[x] = i;
    	city.push_back(x);
    	val[i] = t;
    	if (x == "ROM") {
    		ed = i;
    	}
    }
    while (m--) {
    	cin >> x >> y >> t;
    	e[mp[x]].push_back(edge(mp[y], t));
    	e[mp[y]].push_back(edge(mp[x], t));
    }
    spfa();
    vector<string> ans;
    dfs(ed, ans);
    cout << vis[ed] << ' ' << dis[ed] << ' ' << happy[ed] << ' ' << (int)(happy[ed]/cnt[ed]) << endl;
    cout << city[0];
    for (auto i: ans) {
    	cout << "->" << i;
    }
    cout << endl;
    return 0;
}
