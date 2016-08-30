#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10, mod = 1000000007;
char s[N];
int p[N], t[N];
int main()
{
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		p[i+1] = p[i] + (s[i] == 'P');
	}
	for (int i = l-1; i >= 0; i--) {
		t[i] = t[i+1] + (s[i] == 'T');
	}
	ll ans = 0;
	for (int i = l-1; i > 0; i--) {
		if (s[i] != 'A')
			continue;
		ans = (ans + p[i] * 1LL * t[i]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}