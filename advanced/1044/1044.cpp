#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5+10, inf = 0x3f3f3f3f;
int n, m, a[N], sum[N], mn = inf;
vector<pii> ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		sum[i] = sum[i-1] + a[i];
	}
	sum[n+1] = inf;
	for (int i = 0; i < n; i++) {
		int l = i, r = n, mid, s = n+1;
		while (r-l > 3) {
			mid = (l+r) >> 1;
			if (sum[mid] - sum[i] < m) {
				l = mid;
			} else {
				r = mid;
			}
		}
		for (int j = l; j <= r; j++) {
			if (sum[j] - sum[i] >= m) {
				s = j;
				break;
			}
		}
		int k = sum[s] - sum[i];
		if (k < mn) {
			mn = k;
			ans.clear();
			ans.push_back(pii(i+1, s));
		} else if (k == mn) {
			ans.push_back(pii(i+1, s));
		}
	}
	for (auto i: ans) {
		printf("%d-%d\n", i.first, i.second);
	}
	return 0;
}