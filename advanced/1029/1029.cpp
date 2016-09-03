#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
typedef long long ll;
ll a[N];
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a+i);
	}
	scanf("%d", &m);
	m += n;
	for (int i = n; i < m; i++) {
		scanf("%lld", a+i);
	}
	sort(a, a+m);
	printf("%lld\n", a[(m-1)/2]);
	return 0;
}