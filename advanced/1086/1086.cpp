#include <bits/stdc++.h>
using namespace std;
struct node {
	int v;
	node *l, *r;
	node(int _v = 0): v(_v){l = r = NULL;}
};
char op[9];
int n, v, cnt = 0;
node *build(node *rt) {
	if (cnt >= n) {
		return rt;
	}
	scanf("%s", op);
	if (op[1] == 'o') {
		return rt;
	}
	scanf("%d", &v);
	rt = new node(v);
	cnt++;
	rt->l = build(rt->l);
	rt->r = build(rt->r);
	return rt;
}
void post(node *rt, vector<int> &v) {
	if (rt == NULL) {
		return;
	}
	post(rt->l, v);
	post(rt->r, v);
	v.push_back(rt->v);
}
int main() {
	scanf("%d", &n);
	node *rt = NULL;
	rt = build(rt);
	vector<int> v;
	post(rt, v);
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++) {
		printf(" %d", v[i]);
	}
	puts("");
	return 0;
}