#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 110;
int cnt[N], n, m, f = 0;
vector<pii> ans;
int dfs(int pos, int tot) {
	if (tot == m) {
		f = 1;
		return 1;
	}
	if (pos > m || tot > m) {
		return 0;
	}
	int k = cnt[pos];
	for (int i = k; i > 0; i--) {
		if (dfs(pos+1, tot + pos*i)) {
			ans.push_back(pii(pos, i));
			return 1;
		}
	}
	if (dfs(pos+1, tot)) {
		return 1;
	}
	return 0;
}
int main() {
	int t;
	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%d", &t);
		if (t <= m) {
			cnt[t]++;
		}
	}
	dfs(1, 0);
	reverse(ans.begin(), ans.end());
	if (f) {
		printf("%d", ans[0].first);
		for (int i = 1; i < ans[0].second; i++) {
			printf(" %d", ans[0].first);
		}
		for (int i = 1; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].second; j++) {
				printf(" %d", ans[i].first);
			}
		}
		puts("");
	} else {
		puts("No Solution");
	}
	return 0;
}