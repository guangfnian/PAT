#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], cnt[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(a, a+n);
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]+a[i] == m) {
			if (cnt[a[i]] > 1) {
				f = 1;
				printf("%d %d\n", a[i], a[i]);
				break;
			}
		} else if (cnt[m-a[i]]) {
			f = 1;
			printf("%d %d\n", a[i], m-a[i]);
			break;
		}
	}
	if (!f) puts("No Solution");
	return 0;
}