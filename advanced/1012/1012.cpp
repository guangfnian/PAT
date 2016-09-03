#include <bits/stdc++.h>
using namespace std;
const int N = 2200;
map<int, int> mp;
int mx_rk[N];
char type[N];
int cnt = 1;
struct stu {
	int id, c, m, e, a;
	int rk;
	void init() {
		scanf("%d%d%d%d", &id, &c, &m, &e);
		mp[id] = cnt++;
		a = c+m+e;
		mx_rk[mp[id]] = 0x3f3f3f3f;
	}
}c[N], m[N], e[N], a[N];

int main()
{
	int n, q, t;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		c[i].init();
		m[i] = e[i] = a[i] = c[i];
	}
	sort(c, c+n, [](stu a, stu b){return a.c > b.c;});
	sort(m, m+n, [](stu a, stu b){return a.m > b.m;});
	sort(e, e+n, [](stu a, stu b){return a.e > b.e;});
	sort(a, a+n, [](stu a, stu b){return a.a > b.a;});
	for (int i = 0; i < n; i++) {
		a[i].rk = i+1;
		if (i && a[i].a == a[i-1].a) {
			a[i].rk = a[i-1].rk;
		}
		if (a[i].rk < mx_rk[mp[a[i].id]]) {
			mx_rk[mp[a[i].id]] = a[i].rk;
			type[mp[a[i].id]] = 'A';
		}
	}
	for (int i = 0; i < n; i++) {
		c[i].rk = i+1;
		if (i && c[i].c == c[i-1].c) {
			c[i].rk = c[i-1].rk;
		}
		if (c[i].rk < mx_rk[mp[c[i].id]]) {
			mx_rk[mp[c[i].id]] = c[i].rk;
			type[mp[c[i].id]] = 'C';
		}
	}
	for (int i = 0; i < n; i++) {
		m[i].rk = i+1;
		if (i && m[i].m == m[i-1].m) {
			m[i].rk = m[i-1].rk;
		}
		if (m[i].rk < mx_rk[mp[m[i].id]]) {
			mx_rk[mp[m[i].id]] = m[i].rk;
			type[mp[m[i].id]] = 'M';
		}
	}
	for (int i = 0; i < n; i++) {
		e[i].rk = i+1;
		if (i && e[i].e == e[i-1].e) {
			e[i].rk = e[i-1].rk;
		}
		if (e[i].rk < mx_rk[mp[e[i].id]]) {
			mx_rk[mp[e[i].id]] = e[i].rk;
			type[mp[e[i].id]] = 'E';
		}
	}
	while (q--) {
		scanf("%d", &t);
		if (mp[t] == 0) {
			puts("N/A");
			continue;
		}
		printf("%d %c\n", mx_rk[mp[t]], type[mp[t]]);
	}
	return 0;
}