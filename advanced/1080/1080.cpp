#include <bits/stdc++.h>
using namespace std;
const int N = 4e4+10, M = 110;
vector<int> res[M];
int quota[M];
int vis[N][M];
struct node {
	int ge, gi, g, rk, p;
	vector<int> v;
}stu[N];
vector<node> rk[N];
int main() {
	int n, m, k, t;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", quota+i);
	}
	for (int i = 0; i < n; i++) {
		stu[i].p = i;
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].g = stu[i].ge + stu[i].gi;
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			stu[i].v.push_back(t);
		}
	}
	sort(stu, stu+n, [](node &a, node &b){if (a.g != b.g) {return a.g > b.g;}return a.ge > b.ge;});
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i && stu[i].g == stu[i-1].g && stu[i].ge == stu[i-1].ge) {
			stu[i].rk = stu[i-1].rk;
		} else {
			stu[i].rk = cnt++;
		}
		rk[stu[i].rk].push_back(stu[i]);
	}
	for (int i = 0; i < cnt; i++) {
		for (auto &j: rk[i]) {
			for (int &kk: j.v) {
				if (vis[i][kk] || quota[kk] > 0) {
					res[kk].push_back(j.p);
					quota[kk]--;
					vis[i][kk] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (!res[i].size()) {
			puts("");
			continue;
		}
		sort(res[i].begin(), res[i].end());
		printf("%d", res[i][0]);
		for (int j = 1; j < res[i].size(); j++) {
			printf(" %d", res[i][j]);
		}
		puts("");
	}
	return 0;
}

