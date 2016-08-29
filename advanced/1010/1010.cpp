#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =15;
const ll inf = (ll)(1) << 60;
char a[N], b[N];
ll pow(ll x, ll n) {
	ll ret = 1, base = x;
	while (n) {
		if (n & 1) ret *= base;
		base *= base;
		if (ret < 0 || base < 0) return -1;
		n >>= 1;
	}
	return ret;
}
ll trans(char *s, ll rad) {
	ll l = strlen(s), ret = 0, k;
	for (int i = l-1; i >= 0; i--) {
		if (s[i] >= 'a' && s[i] <= 'z')
			k = s[i]-'a'+10;
		else k = s[i]-'0';
		if (k >= rad)
			return -1;
		ll kk = pow(rad, l-1-i);
		if (kk < 0) return -2;
		kk *= k;
		if (kk < 0) return -2;
		ret += kk;
		if (ret < 0) return -2;
	}
	return ret;
}
ll solve(char *a, char *b, int rad) {
	ll x = trans(a, rad), ans = inf, y;
	ll l = 2, r = inf, mid;
	while (l <= r) {
		mid = l + (r-l)/2;
		y = trans(b, mid);
		if (y < -1 || y > x) {
			r = mid-1;
		} else if (y == x) {
			ans = min(mid, ans);
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	for (ll i = 2; i <= 500; i++) {
		if (trans(b, i) == x) {
			ans = min(ans, i);
			break;
		}
	}
	if (ans != inf) return ans;
	return -1;
}
int main() {
	int tag, rad, ans;
	scanf("%s%s%d%d", a, b, &tag, &rad);
	if (tag == 1)
		ans = solve(a, b, rad);
	else ans = solve(b, a, rad);
	if (ans == -1) puts("Impossible");
	else printf("%lld\n", ans);
	return 0;
}