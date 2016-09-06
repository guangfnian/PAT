#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct rat {
	ll a, x, y;
	rat(ll x = 0, ll y = 1):x(x), y(y){
		if (y < 0) {
			y = -y;
			x = -x;
		}
		ll k = __gcd(abs(x), y);
		if (!k) k = 1;
		x /= k, y /= k;
	}
	friend rat operator + (rat a, rat b) {
		return rat(a.x*b.y + a.y*b.x, a.y*b.y);
	}
	void init() {
		scanf("%lld/%lld", &x, &y);
		if (y == 0) {
			x = 0, y = 1;
		}
		ll k = __gcd(abs(x), abs(y));
		if (!k) k = 1;
		x /= k, y /= k;
	}
	void print() {
		if (y == 0) {
			a = 0, x = 0, y = 1;
		}
		a = x/y;
		x = abs(x);
		x = x%y;
		ll k = __gcd(x, y);
		if (!k) k = 1;
		x /= k, y /= k;
		if (!a) {
			if (!x) {
				puts("0");
			} else {
				printf("%lld/%lld\n", x, y);
			}
		} else {
			if (!x) {
				printf("%lld\n", a);
			} else {
				printf("%lld %lld/%lld\n", a, x, y);
			}
		}
	}
};
int main() {
	int n;
	rat a, b;
	scanf("%d", &n);
	while (n--) {
		b.init();
		a = a+b;
	}
	a.print();
	return 0;
}