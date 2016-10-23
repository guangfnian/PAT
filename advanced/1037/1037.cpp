#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
vector<int> a, b, c, d;
int main() {
	int nc, np, t;
	scanf("%d", &nc);
	while (nc--) {
		scanf("%d", &t);
		if (t > 0) {
			a.push_back(t);
		} else {
			b.push_back(t);
		}
	}
	scanf("%d", &np);
	while (np--) {
		scanf("%d", &t);
		if (t > 0) {
			c.push_back(t);
		} else {
			d.push_back(t);
		}
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end(), greater<int>());
	sort(d.begin(), d.end());
	ll ans = 0;
	for (int i = 0; i < min(a.size(), c.size()); i++) {
		ans += a[i] * 1LL * c[i];
	}
	for (int i = 0; i < min(b.size(), d.size()); i++) {
		ans += b[i] * 1LL * d[i];
	}
	printf("%lld\n", ans);
	return 0;
}

