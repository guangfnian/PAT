#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], bg[N], ls[N], mp[N];

void merge(int l, int m, int r) {
	int p = l, q = m+1, k = l;
	while (p <= m && q <= r) {
		if (a[p] < a[q]) {
			b[k++] = a[p++];
		} else {
			bg[mp[a[q]]] += m-p+1;
			b[k++] = a[q++];
		}
	}
	while (p <= m) {
		b[k++] = a[p++];
	}
	while (q <= r) {
		b[k++] = a[q++];
	}
	for (int i = l; i <= r; i++) {
		a[i] = b[i];
	}
}

void merge_sort(int l, int r) {
	if (l < r) {
		int m = (l+r) >> 1;
		merge_sort(l, m);
		merge_sort(m+1, r);
		merge(l, m, r);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
		mp[a[i]] = i;
	}
	merge_sort(0, n-1);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ls[mp[a[i]]] = bg[mp[a[i]]] + i - mp[a[i]];
	}
	for (int i = 0; i < n; i++) {
		ans += ls[i]*1LL*bg[i];
	}
	printf("%lld\n", ans);
	return 0;
}