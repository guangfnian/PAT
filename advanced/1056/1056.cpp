#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N = 1100;
typedef pair<int, int> pii;
int w[N], cnt = 1, ans[N];
vector<pii> rk;
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	vector<int> x(n), y;
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	while (x.size() > 1) {
		for (int i = 0; i < x.size(); i += m) {
			int mx = -1, k = i;
			for (int j = i; j < i+m && j < x.size(); j++) {
				if (w[x[j]] > mx) {
					mx = w[x[j]];
					k = x[j];
				}
			}
			s.insert(k);
			y.push_back(k);
		}
		for (int i = 0; i < x.size(); i++) {
			if (s.find(x[i]) == s.end()) {
				rk.push_back(pii(cnt, x[i]));
			}
		}
		cnt++;
		x.clear();
		x = y;
		y.clear();
		s.clear();
	}
	rk.push_back(pii(cnt, x[0]));
	sort(rk.begin(), rk.end(), greater<pii>());
	ans[rk[0].Y] = 1;
	for (int i = 1; i < rk.size(); i++) {
		if (rk[i].X != rk[i-1].X) {
			ans[rk[i].Y] = i+1;
		} else {
			ans[rk[i].Y] = ans[rk[i-1].Y];
		}
	}
	printf("%d", ans[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}

