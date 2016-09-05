#include <bits/stdc++.h>
using namespace std;
struct node {
	char name[15], id[15];
	int k;
	void print() {
		printf("%s %s\n", name, id);
	}
}stu[110];
int main() {
	int n, t;
	char s[15], id[15];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", s, id, &t);
		stu[t].k = 1;
		strcpy(stu[t].name, s);
		strcpy(stu[t].id, id);
	}
	int l, r, f = 0;
	scanf("%d%d", &l, &r);
	if (l > r) {
		swap(l, r);
	}
	l = max(0, l), r = min(100, r);
	for (int i = r; i >= l; i--) {
		if (stu[i].k) {
			stu[i].print();
			f = 1;
		}
	}
	if (!f) {
		puts("NONE");
	}
	return 0;
}