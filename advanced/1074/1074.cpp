#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int k, n;
struct node {
	int v, nxt, id;
	void init(int y) {
		id = y;
		scanf("%d%d", &v, &nxt);
	}
}v[N];
vector<node> ans;
int main() {
	int rt, t;
	scanf("%d%d%d", &rt, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v[t].init(t);
	}
	t = rt;
	while (t != -1) {
		ans.push_back(v[t]);
		t = v[t].nxt;
	}
	for (int i = 0; ; i++) {
		int s = i*k, e = s+k;
		if (e > ans.size()) {
			break;
		}
		reverse(ans.begin()+s, ans.begin()+e);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1) {
			printf("%05d %d %05d\n", ans[i].id, ans[i].v, ans[i+1].id);
		} else {
			printf("%05d %d -1\n", ans[i].id, ans[i].v);
		}
	}
	return 0;
}