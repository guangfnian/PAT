#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct node {
	void init(int p) {
		id = p;
		scanf("%d%d", &v, &nxt);
	}
	int id, v, nxt;
}nd[N];
vector<node> ans;
int main() {
	int n, rt, t;
	scanf("%d%d", &n, &rt);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		nd[t].init(t);
	}
	t = rt;
	while (t != -1) {
		ans.push_back(nd[t]);
		t = nd[t].nxt;
	}
	int l = ans.size();
	if (l == 0) {
		puts("0 -1");
		return 0;
	}
	sort(ans.begin(), ans.end(), [](node a, node b){return a.v < b.v;});
	printf("%d %05d\n", l, ans[0].id);
	for (int i = 0; i < l-1; i++) {
		printf("%05d %d %05d\n", ans[i].id, ans[i].v, ans[i+1].id);
	}
	printf("%05d %d -1\n", ans[l-1].id, ans[l-1].v);
	return 0;
}