#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int L[N], R[N], mid[N];
stack<int> ri;
int solve(int l, int r)
{
	if (ri.empty() || l > r)
		return -1;
	int root = ri.top();
	ri.pop();
	if (l == r)
		return root;
	int k;
	for (k = l; k <= r; k++)
		if (mid[k] == root)
			break;
	R[root] = solve(k+1, r);
	L[root] = solve(l, k-1);
	return root;
}
int main()
{
	int n, t;
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		ri.push(t);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &mid[i]);
	int root = solve(0, n-1);
	queue<int> que;
	que.push(root);
	vector<int> ans;
	while (!que.empty())
	{
		int no = que.front();
		que.pop();
		ans.push_back(no);
		if (L[no] != -1)
			que.push(L[no]);
		if (R[no] != -1)
			que.push(R[no]);
	}
	printf("%d", root);
	for (int i = 1; i < ans.size(); i++)
		printf(" %d", ans[i]);
	puts("");
		return 0;
}