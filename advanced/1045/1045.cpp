# include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
unordered_map<int, int> mp;
vector<int> a;
int dp[N];
int solve() {
	int l = a.size(), len = 1;
	dp[0] = a[0];
	for (int i = 1; i < l; i++) {
		int pos = upper_bound(dp, dp+len, a[i]) - dp;
		dp[pos] = a[i];
		len = max(len, pos+1);
	}
	return len;
}
int main() {
	int _, n, t;
	scanf("%d%d", &_, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		mp[t] = i;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		auto k = mp.find(t);
		if (k == mp.end()) {
			continue;
		}
		a.push_back(k->second);
	}
	printf("%d\n", solve());
	return 0;
}