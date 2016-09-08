#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int a[N], b[N], cnt = 0, n;
void dfs(int p) {
	if (p >= n || a[p] == -1) {
		return;
	}
	int l = (p << 1) + 1, r = (p << 1) + 2;
	if (a[l] == -1) {
		a[p] = b[cnt++];
		return;
	}
	dfs(l);
	a[p] = b[cnt++];
	dfs(r);
}
int main() {
	memset(a, -1, sizeof(a));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		a[i] = -2;
	}
	sort(b, b+n);
	dfs(0);
	printf("%d", a[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", a[i]);
	}
	puts("");
	return 0;
}