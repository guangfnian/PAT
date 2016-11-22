#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = 1e4+5;
vector<int> v[N];
//unordered_set<int> ans;
cc_hash_table<int, null_type> ans;
bool vis[N];
int _mx = 0;

void dfs(int x) {
	vis[x] = 1;
	for (int i: v[x]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}

void dfs(int pre, int root, int now, int depth) {
	if (depth > _mx) {
		ans.clear();
		_mx = depth;
	}
	if (depth == _mx)
		ans.insert(root);
	for (int i: v[now]) {
		if (i != pre)
			dfs(now, root, i, depth+1);
	}
}
void solve() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i);
		}
	}
	if (cnt > 1) {
		printf("Error: %d components\n", cnt);
		return;
	}
	for (int i = 1; i <= n; i++) {
		dfs(-1, i, i, 0);
	}
	vector<int> q;
	for (int i: ans)
		q.push_back(i);
	sort(q.begin(), q.end());
	for (int i: q)
		printf("%d\n", i);
}
int main()
{
	solve();
	return 0;
}