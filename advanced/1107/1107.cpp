#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int fa[N], cnt[N];
bitset<N> p[N];
int find(int x) {
	return x == fa[x] ? fa[x]: fa[x] = find(fa[x]);
}
int main() {
	int n, k, t;
	scanf("%d", &n);
	for (int i = 0; i < n+5; i++) {
		fa[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d:", &k);
		while (k--) {
			scanf("%d", &t);
			p[i][t] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((p[i] & p[j]).any()) {
				int x = find(i), y = find(j);
				if (x != y) {
					fa[x] = y;
					cnt[y] += cnt[x];
					cnt[x] = 0;
				}
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (cnt[i]) {
			ans.push_back(cnt[i]);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	printf("%d\n%d", ans.size(), ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}