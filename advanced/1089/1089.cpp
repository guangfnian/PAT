#include <bits/stdc++.h>
using namespace std;
const int N = 400, inf = 0x3f3f3f3f;
int o[N], a[N], b[N], tmp[N], n, to[N];
void merge(int *a, int k) {
	int p = 0;
	while (p < n) {
		sort(a+p, a+p+k);
		p = p+k;
	}
}
void solve() {
	fill(b, b+N, inf);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &o[i]);
		a[i] = b[i] = o[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &to[i]);
	}
	for (int i = 1; i < n; i++) {
		sort(a, a+i+1);
		int f = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != to[i]) {
				f = 0;
				break;
			}
		}
		if (!f) {
			continue;
		}
		sort(a, a+i+2);
		puts("Insertion Sort");
		printf("%d", a[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", a[i]);
		}
		puts("");
		return;
	}
	int p = 1;
	while (1) {
		merge(b, p);
		p <<= 1;
		int f = 1;
		for (int i = 0; i < n; i++) {
			if (b[i] != to[i]) {
				f = 0;
				break;
			}
		}
		if (f) {
			merge(b, p);
			puts("Merge Sort");
			printf("%d", b[0]);
			for (int i = 1; i < n; i++) {
				printf(" %d", b[i]);
			}
			puts("");
			return;
		}
	}
}
int main() {
	solve();
	return 0;
}