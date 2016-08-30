#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main() {
	int n, s1 = 0, s2 = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i = 1; i <= (n >> 1); i++)
		s1 += a[i];
	for (int i = (n >> 1) +1; i <= n; i++)
		s2 += a[i];
	printf("%d %d\n", n&1, s2-s1);
	return 0;
}