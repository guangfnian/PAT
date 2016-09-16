#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
unordered_map<int, int> mp;
int a[N], b[N], ans[N];
void merge(int l, int m, int r) {
	int p = l, q = m+1, k = l;
	while (p <= m && q <= r) {
		if (a[p] <= a[q]) {
			b[k++] = a[p++];
		} else {
			ans[mp[a[q]]] += m-p+1;
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
	for (int i = 0; i < n; i++) {
		ans[mp[a[i]]] += i-mp[a[i]];
	}
	printf("%d", ans[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}