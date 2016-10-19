#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> v[N];
auto mp = [](char *s){return (s[0]-'A'+1)*7290 + (s[1]-'A'+1)*270 + (s[2]-'A'+1)*10 + s[3]-'0';};
int main() {
	char s[5];
	int n, m, a, b, cnt = 1;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		while (b--) {
			scanf("%s", s);
			v[mp(s)].push_back(a);
		}
	}
	while (n--) {
		scanf("%s", s);
		int k = mp(s);
		sort(v[k].begin(), v[k].end());
		printf("%s %d", s, v[k].size());
		for (auto &i: v[k]) {
			printf(" %d", i);
		}
		puts("");
	}
	return 0;
}

