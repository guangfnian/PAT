#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, inf = 0x3f3f3f3f;
int sum[N], a[N];
int main() {
	int n, t, mx = -inf, l, r;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i+1; j <= n; j++)
			if (sum[j]-sum[i] > mx) {
				mx = sum[j]-sum[i];
				l = a[i+1], r = a[j];
			}
	if (mx < 0)
		printf("0 %d %d\n", a[1], a[n]);
	else
		printf("%d %d %d\n", mx, l, r);
	return 0;
}