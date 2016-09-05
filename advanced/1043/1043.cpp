#include <bits/stdc++.h>
using namespace std;

struct node {
	int v;
	node *l, *r;
	node(int _v = 0): v(_v){l = r = NULL;};
};
node *insert(node *rt, int v) {
	if (rt == NULL) {
		return new node(v);
	}
	if (v < rt->v) {
		rt->l = insert(rt->l, v);
	} else {
		rt->r = insert(rt->r, v);
	}
	return rt;
}
node *insert2(node *rt, int v) {
	if (rt == NULL) {
		return new node(v);
	}
	if (v >= rt->v) {
		rt->l = insert2(rt->l, v);
	} else {
		rt->r = insert2(rt->r, v);
	}
	return rt;
}
void pre(const node *rt, vector<int> &v) {
	if (rt == NULL) {
		return;
	}
	v.push_back(rt->v);
	pre(rt->l, v);
	pre(rt->r, v);
}
void post(const node *rt, vector<int> &v) {
	if (rt == NULL) {
		return;
	}
	post(rt->l, v);
	post(rt->r, v);
	v.push_back(rt->v);
}
bool ok(const node *rt, const vector<int> &a) {
	vector<int> v;
	pre(rt, v);
	if (v != a) {
		return false;
	}
	puts("YES");
	v.clear();
	post(rt, v);
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++) {
		printf(" %d", v[i]);
	}
	puts("");
	return true;
}
void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	node *rt1 = NULL, *rt2 = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		rt1 = insert(rt1, a[i]);
		rt2 = insert2(rt2, a[i]);
	}
	if (ok(rt1, a) || ok(rt2, a)) {
		return;
	}
	puts("NO");
}
int main() {
	solve();
	return 0;
}