#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int rk[N], vis[N];
bool isPrime(int x) {
	int k = sqrt(x);
	for (int i = 2; i <= k; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		rk[x] = i;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		printf("%04d: ", x);
		if (!rk[x]) {
			puts("Are you kidding?");
		} else if (vis[x]) {
			puts("Checked");
		} else if (rk[x] == 1) {
			puts("Mystery Award");
		} else if (isPrime(rk[x])) {
			puts("Minion");
		} else {
			puts("Chocolate");
		}
		vis[x] = 1;
	}
	return 0;
}

