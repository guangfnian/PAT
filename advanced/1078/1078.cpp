#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
int m;
bool isPrime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	int x = sqrt(n);
	for (int i = 2; i <= x; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int getPrime(int n) {
	for (int i = n; ; i++) {
		if (isPrime(i)) {
			return i;
		}
	}
}
void solve(int x) {
	int k = x%m;
	for (int i = 0; i < m; i++) {
		int f = (i*i+k) % m;
		if (f >= m) {
			break;
		}
		if (!vis[f]) {
			vis[f] = 1;
			printf("%d", f);
			return;
		}
	}
	putchar('-');
}
int main() {
	int n, t;
	scanf("%d%d", &m, &n);
	m = getPrime(m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		solve(t);
		if (i != n-1) {
			putchar(' ');
		} else {
			puts("");
		}
	}
	return 0;
}