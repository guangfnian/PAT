#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
double r, ans = 1e20;
int cnt;
vector<int> v[N];
bool ed[N];
void dfs(int pos, double p) {
	if (ed[pos]) {
		if (fabs(p - ans) < 1e-8) {
			cnt++;
		} else if (p < ans) {
			ans = p;
			cnt = 1;
		}
	} else {
		for (int &i: v[pos]) {
			dfs(i, p*r);
		}
	}
}
int main() {
	int n, k, t;
	double p;
	scanf("%d%lf%lf", &n, &p, &r);
	r = (1.0 + r/100.0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (!k) {
			ed[i] = 1;
		} else {
			while (k--) {
				scanf("%d", &t);
				v[i].push_back(t);
			}
		}
	}
	dfs(0, p);
	printf("%.4f %d\n", ans, cnt);
	return 0;
}

