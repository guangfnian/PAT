#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, level;
	node *l, *r;
	node(int _v = 0, int _l = 0): v(_v), level(_l){l = r = NULL;}
};
int mx, n1, n2;
node *insert(node *rt, int v, int l = 0) {
	if (rt == NULL) {
		mx = max(mx, l);
		return new node(v, l);
	}
	if (v <= rt->v) {
		rt->l = insert(rt->l, v, l+1);
	} else {
		rt->r = insert(rt->r, v, l+1);
	}
	return rt;
}
void dfs(node *rt) {
	if (rt == NULL) {
		return;
	}
	if (rt->level == mx) {
		n1++;
	} else if (rt->level == mx-1) {
		n2++;
	}
	dfs(rt->l);
	dfs(rt->r);
}
int main() {
	int n, t;
	mx = n1 = n2 = 0;
	scanf("%d", &n);
	node *rt = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		rt = insert(rt, t);
	}
	dfs(rt);
	printf("%d + %d = %d\n", n1, n2, n1+n2);
	return 0;
}