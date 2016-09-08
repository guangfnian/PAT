#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct node {
	int id, v, nxt;
	void init(int p) {
		id = p;
		scanf("%d%d", &v, &nxt);
	}
}lst[N];
vector<node> x, y;
unordered_map<int, int> mp;
void print(vector<node> &ans) {
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size()-1) {
			printf("%05d %d %05d\n", ans[i].id, ans[i].v, ans[i+1].id);
		} else {
			printf("%05d %d -1\n", ans[i].id, ans[i].v);
		}
	}
}
int main() {
	int rt, n, t;
	scanf("%d%d", &rt, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		lst[t].init(t);
	}
	t = rt;
	while (t != -1) {
		if (!mp[abs(lst[t].v)]) {
			mp[abs(lst[t].v)] = 1;
			x.push_back(lst[t]);
		} else {
			y.push_back(lst[t]);
		}
		t = lst[t].nxt;
	}
	print(x);
	print(y);
	return 0;
}