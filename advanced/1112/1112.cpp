#include <bits/stdc++.h>
using namespace std;
int ok[128], no[128], vis[128];
int main() {
	char s[1100];
	int k;
	scanf("%d%s", &k, s);
	int l = strlen(s);
	int st = 0, ed = 0;
	while (st < l && ed < l) {
		while (ed < l && s[ed] == s[st]) {
			ed++;
		}
		if ((ed - st) % k == 0) {
			ok[s[st]] = 1;
		} else {
			no[s[st]] = 1;
		}
		st = ed;
	}
	vector<char> ans;
	for (int i = 0; i < l; i++) {
		if (ok[s[i]] && !no[s[i]] && !vis[s[i]]) {
			ans.push_back(s[i]);
			vis[s[i]] = 1;
		}
	}
	for (char &i: ans) {
		putchar(i);
	}
	puts("");
	st = 0, ed = 0;
	while (st < l && ed < l) {
		while (ed < l && s[ed] == s[st]) {
			ed++;
		}
		if (ok[s[st]] && !no[s[st]]) {
			int t = (ed - st) / k;
			for (int i = 0; i < t; i++) {
				putchar(s[st]);
			}
		} else {
			int t = ed - st;
			for (int i = 0; i < t; i++) {
				putchar(s[st]);
			}
		}
		st = ed;
	}
	puts("");
	return 0;
}

