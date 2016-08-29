#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> P;
const int N = 1100;
double s[N];
bool vis[N];
vector<P> v;
int main() {
	int k, n;
	double x;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &n, &x);
		vis[n] = 1;
		s[n] += x;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &n, &x);
		vis[n] = 1;
		s[n] += x;
	}
	for (int i = 1005; i >= 0; i--) {
		if (vis[i]) {
			if (fabs(s[i]) < 1e-8)
				continue;
			v.push_back(P(i, s[i]));
		}
	}
	printf("%d", v.size());
	for (auto vv: v)
		printf(" %d %.1f", vv.first, vv.second);
	puts("");
	return 0;
}