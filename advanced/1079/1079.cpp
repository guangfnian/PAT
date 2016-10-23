#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> v[N];
double num[N], r, ans;
void dfs(int pos, double p) {
	ans += p*num[pos];
	for (int i: v[pos]) {
		dfs(i, p*r);
	}
}
int main() {
	int n, k, t;
	double p;
	scanf("%d%lf%lf", &n, &p, &r);
	r = 1.0 + (r/100.0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (!k) {
			scanf("%lf", &num[i]);
		} else {
			while (k--) {
				scanf("%d", &t);
				v[i].push_back(t);
			}
		}
	}
	dfs(0, p);
	printf("%.1f\n", ans);
	return 0;
}

