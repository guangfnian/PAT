#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int p[6], k;
struct node {
	int id, cnt, rk, sum, ok;
	int score[6];
	void init(int x) {
		cnt = sum = ok = 0;
		id = x;
		memset(score, -1, sizeof(score));
	}
	void print() {
		printf("%d %05d %d", rk, id, sum);
		for (int i = 1; i <= k; i++) {
			if (score[i] != -1) {
				printf(" %d", score[i]);
			} else {
				printf(" -");
			}
		}
		puts("");
	}
}stu[N];
int main() {
	int n, m, x, t, s;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		stu[i].init(i);
	}
	while (m--) {
		scanf("%d%d%d", &x, &t, &s);
		s = max(s, 0);
		stu[x].score[t] = max(stu[x].score[t], s);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] == -1) {
				continue;
			}
			stu[i].ok = 1;
			stu[i].sum += stu[i].score[j];
			stu[i].cnt += stu[i].score[j] == p[j];
		}
	}
	sort(stu+1, stu+n+1, 
		[](const node &a, const node &b) {
			return a.sum > b.sum;
	});
	for (int i = 1; i <= n; i++) {
		if (i > 1 && stu[i].sum == stu[i-1].sum) {
			stu[i].rk = stu[i-1].rk;
		} else {
			stu[i].rk = i;
		}
	}
	sort(stu+1, stu+n+1,
		[](const node &a, const node &b) {
			if (a.rk != b.rk) {
				return a.rk < b.rk;
			}
			if (a.cnt != b.cnt) {
				return a.cnt > b.cnt;
			}
			return a.id < b.id;
	});
	for (int i = 1; i <= n; i++) {
		if (stu[i].ok) {
			stu[i].print();
		} else {
			break;
		}
	}
	return 0;
}

