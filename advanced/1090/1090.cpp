#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> v[N];
int mx, tot;
void dfs(int p, int depth) {
	if (depth > mx) {
		mx = depth;
		tot = 1;
	} else if (depth == mx) {
		tot++;
	}
	for (int i: v[p]) {
		dfs(i, depth+1);
	}
}
int main() {
	int n, rt, t;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t == -1) {
			rt = i;
		} else {
			v[t].push_back(i);
		}
	}
	dfs(rt, 0);
	printf("%.2f %d\n", p*pow(1.0+r/100.0, mx+0.0), tot);
	return 0;
}