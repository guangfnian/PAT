#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
int vis[N], mx, tot_num, tot_sum, cnt = 0, sum[N], val[N][N];
string name[N], heads;
struct node {
	string name;
	int num;
	bool friend operator < (node a, node b) {
		return a.name < b.name;
	}
	node(){}
	node(string n, int v){name = n, num = v;}
};
vector<node> ans;
map<string, int> mp;
vector<int> e[N];
void dfs(int p, vector<int> &v) {
	v.push_back(p);
	vis[p] = 1;
	tot_num++;
	if (sum[p] > mx) {
		mx = sum[p];
		heads = name[p];
	}
	for (int x: e[p]) {
		if (!vis[x]) {
			dfs(x, v);
		}
	}
}
vector<int> vv;
int main() {
	std::ios::sync_with_stdio(false);
	int n, K, t;
	string a, b;
	cin >> n >> K;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> t;
		if (mp[a] == 0) {
			mp[a] = ++cnt;
			name[cnt] = a;
		}
		if (mp[b] == 0) {
			mp[b] = ++cnt;
			name[cnt] = b;
		}
		sum[mp[a]] += t;
		sum[mp[b]] += t;
		e[mp[a]].push_back(mp[b]);
		e[mp[b]].push_back(mp[a]);
		val[mp[a]][mp[b]] += t;
		val[mp[b]][mp[a]] += t;
	}
	for (int i = 1; i <= cnt; i++) {
		if (vis[i]) {
			continue;
		}
		vv.clear();
		mx = tot_sum = tot_num = 0;
		dfs(i, vv);
		for (int i = 0; i < vv.size(); i++) {
			for (int j = i+1; j < vv.size(); j++) {
				tot_sum += val[vv[i]][vv[j]];
			}
		}
		if (tot_sum > K && tot_num > 2) {
			ans.push_back(node(heads, tot_num));
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto i: ans) {
		cout << i.name << ' ' << i.num << endl;
	}
	return 0;
}