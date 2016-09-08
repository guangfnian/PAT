#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int L[N], R[N], a[N], b[N], cnt = 0;
void dfs(int p) {
	if (p == -1) {
		return;
	}
	dfs(L[p]);
	b[p] = a[cnt++];
	dfs(R[p]);
}
int main() {
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	int n, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &l, &r);
		L[i] = l;
		R[i] = r;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	dfs(0);
	vector<int> ans;
	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		if (L[t] != -1) {
			que.push(L[t]);
			ans.push_back(b[L[t]]);
		}
		if (R[t] != -1) {
			que.push(R[t]);
			ans.push_back(b[R[t]]);
		}
	}
	printf("%d", b[0]);
	for (int i: ans) {
		printf(" %d", i);
	}
	puts("");
	return 0;
}