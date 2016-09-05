#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll a[N];
int main() {
	int n, ans = 0;
	ll p;
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		int l = upper_bound(a, a+n, a[i]*p) - a;
		ans = max(ans, l-i);
	}
	printf("%d\n", ans);
	return 0;
}