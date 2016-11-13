#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	int ans = 0;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i *= 10) {
		ll t = n/i % 10;
		if (t > 1) {
			ans += (n/i/10 + 1) * i;
		} else if (t == 1) {
			ans += n/i/10*i + (n%i + 1);
		} else {
			ans += n/i/10*i;
		}
	}
	printf("%d\n", ans);
	return 0;
}

