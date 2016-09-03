#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
struct node {
	double n;
	double p;
}s[N];
int main()
{
	int n, m, tot = 0;
	double ans = 0, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &s[i].n);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &t);
		s[i].p = t/s[i].n;
	}
	sort(s, s+n, [](node a, node b){return a.p > b.p;});
	for (int i = 0; i < n; i++) {
		if (tot + s[i].n < m) {
			tot += s[i].n;
			ans += s[i].n * s[i].p;
		} else {
			ans += (m-tot) * s[i].p;
			tot = m;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}