#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int val[N], s;
vector<int> v[N];
vector<vector<int>> ans;
void dfs(int rt, int sum, vector<int> x) {
	if (sum > s) {
		return;
	}
	if (sum == s && v[rt].empty()) {
		ans.push_back(x);
	}
	for (int i: v[rt]) {
		x.push_back(val[i]);
		dfs(i, sum+val[i], x);
		x.erase(x.end()-1);
	}
}
int main() {
	int n, m, r, k, t;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", val+i);
	}
	while (m--) {
		scanf("%d%d", &r, &k);
		while (k--) {
			scanf("%d", &t);
			v[r].push_back(t);
		}
	}
	vector<int> x;
	x.push_back(val[0]);
	dfs(0, val[0], x);
	sort(ans.begin(), ans.end(), greater<vector<int>>());
	for (auto &i: ans) {
		printf("%d", i[0]);
		for (int j = 1; j < i.size(); j++) {
			printf(" %d", i[j]);
		}
		puts("");
	}
	return 0;
}

