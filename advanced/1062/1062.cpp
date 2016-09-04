#include <bits/stdc++.h>
using namespace std;
struct node{
	int id, vir, tal;
	void init() {
		scanf("%d%d%d", &id, &vir, &tal);
	}
	bool friend operator < (node a, node b) {
		if (a.vir+a.tal != b.vir+b.tal)
			return a.vir+a.tal > b.vir+b.tal;
		if (a.vir != b.vir)
			return a.vir > b.vir;
		return a.id < b.id;
	}
	void print() {
		printf("%d %d %d\n", id, vir, tal);
	}
}tmp;
vector<node> sage, noble, fool, small;
void solve(vector<node> x) {
	sort(x.begin(), x.end());
	for (auto i: x)
		i.print();
}
int main()
{
	int n, l, h, tot = 0;
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0; i < n; i++) {
		tmp.init();
		if (tmp.vir < l || tmp.tal < l) {
			continue;
		}
		if (tmp.vir >= h && tmp.tal >= h) {
			sage.push_back(tmp);
		} else if (tmp.vir >= h) {
			noble.push_back(tmp);
		} else if (tmp.vir >= tmp.tal) {
			fool.push_back(tmp);
		} else {
			small.push_back(tmp);
		}
		tot++;
	}
	printf("%d\n", tot);
	solve(sage);
	solve(noble);
	solve(fool);
	solve(small);
	return 0;
}