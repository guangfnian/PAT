#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], cnt[N];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] == 1) {
			printf("%d\n", a[i]);
			return;
		}
	}
	puts("None");
}
int main() {
	solve();
	return 0;
}