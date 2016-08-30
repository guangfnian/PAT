#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int main() {
	int n;
	scanf("%d", &n);
	double ans = 0, t;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &t);
		ans += t*(i+1.0)*(n-i);
	}
	printf("%.2f\n", ans);
	return 0;
}