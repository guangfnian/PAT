#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef pair<int, int> pii;
vector<int> v[N];
bool vis[N];
int cnt[N];
int main() {
	int n, m, r, k, t;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &r, &k);
		while (k--) {
			scanf("%d", &t);
			v[r].push_back(t);
		}
	}
	int mx = 0, level;
	queue<pii> que;
	que.push(pii(1, 1));
	vis[1] = 1;
	while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		que.pop();
		cnt[y]++;
		if (cnt[y] > mx) {
			mx = cnt[y];
			level = y;
		}
		for (int i: v[x]) {
			if (!vis[i]) {
				que.push(pii(i, y+1));
			}
		}
	}
	printf("%d %d\n", mx, level);
	return 0;
}