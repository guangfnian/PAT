#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int sum[N], x;
int main()
{
	int n, t, m, l, r;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &t);
		sum[i] = sum[i-1]+t;
	}
	scanf("%d%d", &x, &m);
	while (m--) {
		scanf("%d%d", &l, &r);
		if (l > r) {
			swap(l, r);
		}
		printf("%d\n", min(sum[r]-sum[l], sum[l]+sum[n]-sum[r]+x));
	}
	return 0;
}