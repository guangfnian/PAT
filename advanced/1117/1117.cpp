#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
	}
	sort(a, a+n, greater<int>());
	int ans = 0, p = 0;
	while (ans <= n && a[p] > p+1) {
		ans++;
		p++;
	}
	printf("%d\n", ans);
	return 0;
}

