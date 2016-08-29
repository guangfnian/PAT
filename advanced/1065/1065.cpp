#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		ll a, b, c;
		__int128 x, y, z;
		scanf("%lld%lld%lld", &a, &b, &c);
		x = a, y = b, z = c;
		printf("Case #%d: %s\n", cas, (x+y > c ? "true": "false"));
	}
	return 0;
}