#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int L[N], R[N], n, vis[N], tree[N];
void dfs(int rt, int pos) {
	tree[pos] = rt;
	if (L[rt] != -1) {
		dfs(L[rt], pos*2+1);
	}
	if (R[rt] != -1) {
		dfs(R[rt], pos*2+2);
	}
}
void solve() {
	int n, k, root;
	char s[5];
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	memset(tree, -1, sizeof(tree));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		if (s[0] != '-') {
			k = atoi(s);
			L[i] = k;
			vis[k] = 1;
		}
		scanf("%s", s);
		if (s[0] != '-') {
			k = atoi(s);
			R[i] = k;
			vis[k] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			root = i;
			break;
		}
	}
	dfs(root, 0);
	for (int i = 0; i < n; i++) {
		if (tree[i] == -1) {
			printf("NO %d\n", root);
			return;
		}
	}
	printf("YES %d\n", tree[n-1]);
}
int main() {
	solve();
	return 0;
}

