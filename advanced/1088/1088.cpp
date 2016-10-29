#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct fen {
	ll x, y;
	fen(ll _x = 0, ll _y = 1) {
		x = _x, y = _y;
		init();
	}
	void init() {
		ll k = __gcd(x, y);
		if (k) {
			x /= k;
			y /= k;
		} else {
			x = 0, y = 1;
		}
		if (y < 0) {
			x = -x;
			y = -y;
		}
	}
	friend fen operator + (const fen &a, const fen &b) {
		return fen(a.x*b.y + b.x*a.y, a.y*b.y);
	}
	friend fen operator - (const fen &a, const fen &b) {
		return fen(a.x*b.y - b.x*a.y, a.y*b.y);
	}
	friend fen operator * (const fen &a, const fen &b) {
		return fen(a.x*b.x, a.y*b.y);
	}
	friend fen operator / (const fen &a, const fen &b) {
		return fen(a.x*b.y, a.y*b.x);
	}
	void print() {
		if (x == 0) {
			putchar('0');
		} else if (x > 0) {
			if (x/y) {
				if (x % y) {
					printf("%d %d/%d", x/y, x%y, y);
				} else {
					printf("%d", x/y);
				}
			} else {
				printf("%d/%d", x, y);
			}
		} else {
			if (x/y) {
				if (-x % y) {
					printf("(-%d %d/%d)", -x/y, -x%y, y);
				} else {
					printf("(%d)", x/y);
				}
			} else {
				printf("(%d/%d)", x, y);
			}
		}
	}
};
int main() {
	int a, b, x, y;
	scanf("%d/%d%d/%d", &a, &b, &x, &y);
	fen A(a, b), B(x, y);
	A.print();
	printf(" + ");
	B.print();
	printf(" = ");
	(A+B).print();
	puts("");
	A.print();
	printf(" - ");
	B.print();
	printf(" = ");
	(A-B).print();
	puts("");
	A.print();
	printf(" * ");
	B.print();
	printf(" = ");
	(A*B).print();
	puts("");
	A.print();
	printf(" / ");
	B.print();
	printf(" = ");
	if (B.x) {
		(A/B).print();
	} else {
		printf("Inf");
	}
	puts("");
	return 0;
}

