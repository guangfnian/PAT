#include <bits/stdc++.h>
using namespace std;
int m, n, a[1100];
void solve() {
	int cur = 1, t;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 0; i < n; i++) {
		int t = a[i];
		if (s.empty() || s.top() < t) {
			if (t-cur+1+s.size() > m) {
				puts("NO");
				return;
			}
			while (cur < t) {
				s.push(cur++);
			}
			cur++;
		} else if (s.top() == t) {
			s.pop();
		} else {
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main() {
	int k;
	scanf("%d%d%d", &m, &n, &k);
	while (k--) {
		solve();
	}
	return 0;
}