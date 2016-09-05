#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> nxt, vis;
void print(int f) {
	if (f == -1) {
		puts("-1");
		return;
	}
	vector<int> v;
	while (f) {
		v.push_back(f%10);
		f /= 10;
	}
	for (int i = 0; i+v.size() < 5; i++) {
		putchar('0');
	}
	reverse(v.begin(), v.end());
	for (int x: v)
		printf("%d", x);
	puts("");
}
int main() {
	int rt1, rt2, n, a, b;
	char s[2];
	scanf("%d%d%d", &rt1, &rt2, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%s%d", &a, s, &b);
		nxt[a] = b;
	}
	int tmp = rt1;
	while (1) {
		vis[tmp] = 1;
		auto t = nxt.find(tmp);
		if (t == nxt.end() || t->second == -1) {
			break;
		}
		tmp = t->second;
	}
	int f = -1;
	tmp = rt2;
	while (1) {
		if (vis.find(tmp) !=  vis.end()) {
			f = tmp;
			break;
		}
		auto t = nxt.find(tmp);
		if (t == nxt.end() || t->second == -1) {
			break;
		}
		tmp = t->second;
	}
	print(f);
	return 0;
}