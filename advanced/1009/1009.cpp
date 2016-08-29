#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
typedef pair<int, double> P;
double ans[N];
vector<P> a, b, v;
int main() {
	int n, x;
	double y;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%lf", &x, &y);
		a.push_back(P(x, y));
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d%lf", &x, &y);
		b.push_back(P(x, y));
	}
	for (auto i: a)
		for (auto j: b)
			ans[i.first+j.first] += i.second*j.second;
	for (int i = 2005; i >= 0; i--) {
		if (fabs(ans[i]) < 1e-8)
			continue;
		v.push_back(P(i, ans[i]));
	}
	printf("%d", v.size());
	for (auto i: v)
		printf(" %d %.1f", i.first, i.second);
	puts("");
	return 0;
}