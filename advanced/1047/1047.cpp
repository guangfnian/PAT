#include <bits/stdc++.h>
using namespace std;
vector<char*> v[3300];
int main() {
	int n, m, k, c;
	scanf("%d%d", &n, &m);
	char *s = new char[5];
	while (n--) {
		scanf("%s%d", s, &k);
		while (k--) {
			scanf("%d", &c);
			v[c].push_back(s);
		}
		s = new char[5];
	}
	for (int i = 1; i <= m; i++) {
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end(), [](const char* a, const char* b){return strcmp(a, b) < 0;});
		for (auto &j: v[i]) {
			puts(j);
		}
	}
	return 0;
}
