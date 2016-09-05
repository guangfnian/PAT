#include <bits/stdc++.h>
using namespace std;
int n, d;
bool isPrime(int x) {
	if (x < 2) return 0;
	if (x == 2) return 1;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
void solve() {
	scanf("%d", &d);
	if (!isPrime(n)) {
		puts("No");
		return;
	}
	vector<int> v;
	while (n >= d) {
		v.push_back(n%d);
		n /= d;
	}
	v.push_back(n);
	reverse(v.begin(), v.end());
	int ret = 0, p = 1;
	for (int i = 0; i < v.size(); i++) {
		ret += v[i]*p;
		p *= d;
	}
	puts((isPrime(ret) ? "Yes" : "No"));
}
int main() {
	while (~scanf("%d", &n) && n >= 0) {
		solve();
	}
	return 0;
}