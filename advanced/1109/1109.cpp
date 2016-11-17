#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct node {
	char name[9];
	int h;
	friend bool operator < (const node &a, const node &b) {
		if (a.h != b.h) {
			return a.h > b.h;
		}
		return strcmp(a.name, b.name) < 0;
	}
}stu[N];
deque<int> q[15];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", stu[i].name, &stu[i].h);
	}
	sort(stu, stu+n);
	int p = n/k, st = 0, ed = p + n%k;
	int t = 0, s;
	while (st < n && ed <= n) {
		q[t].push_back(st);
		s = 0;
		for (int i = st+1; i < ed; i++) {
			if (!s) {
				q[t].push_front(i);
			} else {
				q[t].push_back(i);
			}
			s ^= 1;
		}
		st = ed;
		ed += p;
		t++;
	}
	for (int i = 0; i < k; i++) {
		printf("%s", stu[q[i][0]].name);
		for (int j = 1; j < q[i].size(); j++) {
			printf(" %s", stu[q[i][j]].name);
		}
		puts("");
	}
	return 0;
}

