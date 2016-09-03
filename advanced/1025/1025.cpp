#include <bits/stdc++.h>
using namespace std;
struct stu {
	char name[15];
	int val, pos, rk, fn_rk;
	void init(int i) {
		scanf("%s%d", name, &val);
		pos = i;
	}
}tmp;
vector<stu> v, ans;
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		v.clear();
		for (int j = 0; j < m; j++) {
			tmp.init(i+1);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), [](stu a, stu b){return a.val > b.val;});
		for (int j = 0; j < v.size(); j++) {
			v[j].rk = j+1;
			if (j && v[j].val == v[j-1].val) {
				v[j].rk = v[j-1].rk;
			}
		}
		for (stu j: v)
			ans.push_back(j);
	}
	sort(ans.begin(), ans.end(), [](stu a, stu b){if (a.val != b.val)return a.val > b.val;return strcmp(a.name, b.name) < 0;});
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		ans[i].fn_rk = i+1;
		if (i && ans[i].val == ans[i-1].val) {
			ans[i].fn_rk = ans[i-1].fn_rk;
		}
		printf("%s %d %d %d\n", ans[i].name, ans[i].fn_rk, ans[i].pos, ans[i].rk);
	}
	return 0;
}