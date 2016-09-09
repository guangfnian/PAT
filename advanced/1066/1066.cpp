#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, b;
	node *l, *r;
	node(int v = 0, int b = 1):v(v), b(b){l = r = NULL;}
};
int get_h(node *rt) {
	if (rt == NULL) {
		return 0;
	}
	return rt->b;
}
node *l_l(node *rt) {
	node *nrt = rt->l;
	rt->l = nrt->r;
	nrt->r = rt;
	rt->b = max(get_h(rt->l), get_h(rt->r)) + 1;
	nrt->b = max(get_h(nrt->l), rt->b) + 1;
	return nrt;
}
node *r_r(node *rt) {
	node *nrt = rt->r;
	rt->r = nrt->l;
	nrt->l = rt;
	rt->b = max(get_h(rt->l), get_h(rt->r)) + 1;
	nrt->b = max(get_h(nrt->r), rt->b) + 1;
	return nrt;
}
node *l_r(node *rt) {
	rt->l = r_r(rt->l);
	return l_l(rt);
}
node *r_l(node *rt) {
	rt->r = l_l(rt->r);
	return r_r(rt);
}
node *insert(node *rt, int v) {
	if (rt == NULL) {
		rt = new node(v);
	}
	else if (v < rt->v) {
		rt->l = insert(rt->l, v);
		if (get_h(rt->l) - get_h(rt->r) == 2) {
			if (v < rt->l->v) {
				rt = l_l(rt);
			} else {
				rt = l_r(rt);
			}
		}
	} else {
		rt->r = insert(rt->r, v);
		if (get_h(rt->r) - get_h(rt->l) == 2) {
			if (v > rt->r->v) {
				rt = r_r(rt);
			} else {
				rt = r_l(rt);
			}
		}
	}
	rt->b = max(get_h(rt->l), get_h(rt->r)) + 1;
	return rt;
}
int main() {
	int n, t;
	node *rt = NULL;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		rt = insert(rt, t);
	}
	printf("%d\n", rt->v);
	return 0;
}