#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct node {
	string s;
	bool friend operator < (node a, node b) {
		return a.s+b.s < b.s+a.s;
	}
}s[N];
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].s;
	}
	sort(s, s+n);
	int f = 0;
	for (int i = 0; i < n; i++) {
		if (f) {
			cout << s[i].s;
		} else {
			int j = 0;
			while (j < s[i].s.size() && s[i].s[j] == '0') {
				j++;
			}
			if (j == s[i].s.size()) {
				continue;
			}
			f = 1;
			for (; j < s[i].s.size(); j++) {
				cout << s[i].s[j];
			}
		}
	}
	if (!f) {
		cout << 0;
	}
	cout << endl;
	return 0;
}