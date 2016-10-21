#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int fa[N], vis[N];
int find(int x) {
	return x == fa[x]? fa[x]: fa[x] = find(fa[x]);
}
int main() {
	int n, k, x, y, q;
	for (int i = 1; i < N; i++) {
		fa[i] = i;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		k--;
		scanf("%d", &x);
		vis[x] = 1;
		int t = find(x);
		while (k--) {
			scanf("%d", &y);
			fa[find(y)] = fa[t];
			vis[y] = 1;
		}
	}
	int tree = 0, bird = 0;
	for (int i = 1; i < N; i++) {
		if (vis[i]) {
			bird++;
			tree += fa[i] == i;
		}
	}
	printf("%d %d\n", tree, bird);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		puts((find(x) == find(y)) ? "Yes" : "No");
	}
	return 0;
}

