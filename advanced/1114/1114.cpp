#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<int> ch[N];
int d[1100], vis[N], cnt[N], area[N];
int sm_id, tot_num, tot_set, tot_area;
struct node {
	int id, num, ts, ta;
	node(int a, int b, int c, int d): id(a), num(b), ts(c), ta(d){}
	bool friend operator < (const node &a, const node &b) {
		if (a.ta*b.num != b.ta*a.num) {
			return a.ta*b.num > b.ta*a.num;
		}
		return a.id < b.id;
	}
};
void dfs(int p) {
	vis[p] = 1;
	sm_id = min(sm_id, p);
	tot_set += cnt[p];
	tot_area += area[p];
	tot_num++;
	for (int &i: ch[p]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}
int main() {
	int n, k, t;
	scanf("%d", &n);
	for (int _ = 0; _ < n; _++) {
		scanf("%d", &d[_]);
		int id = d[_];
		scanf("%d", &t);
		if (t != -1) {
			ch[id].push_back(t);
			ch[t].push_back(id);
		}
		scanf("%d", &t);
		if (t != -1) {
			ch[id].push_back(t);
			ch[t].push_back(id);
		}
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &t);
			ch[id].push_back(t);
			ch[t].push_back(id);
		}
		scanf("%d%d", &cnt[id], &area[id]);
	}
	vector<node> ans;
	for (int i = 0; i < n; i++) {
		if (vis[d[i]]) {
			continue;
		}
		sm_id = 0x3f3f3f3f;
		tot_area = tot_num = tot_set = 0;
		dfs(d[i]);
		ans.push_back(node(sm_id, tot_num, tot_set, tot_area));
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto &i: ans) {
		printf("%04d %d %.3f %.3f\n", i.id, i.num, i.ts/(i.num+0.0), i.ta/(i.num+0.0));
	}
	return 0;
}

