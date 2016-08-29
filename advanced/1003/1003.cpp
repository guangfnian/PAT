#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
const int N = 550, inf = 0x3f3f3f3f;
vector<P> e[N];
int mx = inf, cnt = 1, mx_num = 0, val[N];
bool vis[N];
void dfs(int st, int ed, int length, int num) {
	if (st == ed) {
		if (length < mx) {
			mx = length;
			cnt = 1;
			mx_num = num;
		}
		else if (length == mx) {
			cnt++;
			mx_num = max(mx_num, num);
		}
		return;
	}
	if (length > mx)
		return;
	for (auto v: e[st]) {
		if (!vis[v.X]) {
			vis[v.X] = 1;
			dfs(v.X, ed, length+v.Y, num+val[v.X]);
			vis[v.X] = 0;
		}
	}
}
int main() {
	int n, m, st, ed, u, v, c;
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);
	while (m--) {
		scanf("%d%d%d", &u, &v, &c);
		e[u].push_back(P(v, c));
		e[v].push_back(P(u, c));
	}
	vis[st] = 1;
	dfs(st, ed, 0, val[st]);
	printf("%d %d\n", cnt, mx_num);
	return 0;
}