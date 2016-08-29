#include <bits/stdc++.h>
using namespace std;
struct stu {
	char id[20];
	int s, e;
}tmp;
vector<stu> v;
int main() {
	int n, h, m, s;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d:%d:%d", tmp.id, &h, &m, &s);
		tmp.s = h*3600 + m*60 + s;
		scanf("%d:%d:%d", &h, &m, &s);
		tmp.e = h*3600 + m*60 + s;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), [](stu a, stu b){return a.s < b.s;});
	printf("%s ", v[0].id);
	sort(v.begin(), v.end(), [](stu a, stu b){return a.e > b.e;});
	puts(v[0].id);
	return 0;
}