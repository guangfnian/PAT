#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], p[N];
unordered_set<int> s;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
		p[a[i]] = i;
		if (a[i] != i) {
			s.insert(a[i]);
		}
	}
	int ans = 0;
	s.erase(0);
	while (!s.empty()) {
		if (a[0] != 0) {
			int u = p[0], v = p[u];
			p[0] = v;
			p[u] = u;
			swap(a[u], a[v]);
			s.erase(u);
		} else {
			int u = *(s.begin()), v = p[u];
			a[0] = u, a[v] = 0;
			p[0] = v, p[u] = 0;
		}
		ans++;
	}
	for (auto i: s) {
		printf("%d\n", i);
	}
	printf("%d\n", ans);
	return 0;
}
