#include <bits/stdc++.h>
using namespace std;
const int N = 110;
bool vis[N];
int level[N], mx = 0;
struct node {
	vector<int> nxt;
}nd[N];
void dfs(int pos, int depth)
{
	mx = max(mx, depth);
	if (!vis[pos])
	{
		level[depth]++;
		return;
	}
	for (int v: nd[pos].nxt)
		dfs(v, depth+1);
}
int main() {
	int n, m, rt, k, t;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &rt, &k);
		if (k != 0)
			vis[rt] = 1;
		while (k--) {
			scanf("%d", &t);
			nd[rt].nxt.push_back(t);
		}
	}
	dfs(1, 0);
	printf("%d", level[0]);
	for (int i = 1; i <= mx; i++)
		printf(" %d", level[i]);
	puts("");
}