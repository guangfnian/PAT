#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int L[N], R[N];
bool vis[N];
void dfs(int rt, vector<int> &v) {
	if (L[rt] != -1)
		dfs(L[rt], v);
	v.push_back(rt);
	if (R[rt] != -1)
		dfs(R[rt], v);
}
int main() {
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	int n;
	char l[2], r[2];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", r, l);
		if (l[0] != '-') {
			vis[l[0]-'0'] = 1;
			L[i] = l[0]-'0';
		}
		if (r[0] != '-') {
			vis[r[0]-'0'] = 1;
			R[i] = r[0]-'0';
		}
	}
	int root;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			root = i;
	queue<int> q;
	vector<int> v;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (L[t] != -1) {
			q.push(L[t]);
			v.push_back(L[t]);
		}
		if (R[t] != -1) {
			q.push(R[t]);
			v.push_back(R[t]);
		}
	}
	printf("%d", root);
	for (int i: v)
		printf(" %d", i);
	puts("");
	v.clear();
	dfs(root, v);
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++)
		printf(" %d", v[i]);
	puts("");
	return 0;
}