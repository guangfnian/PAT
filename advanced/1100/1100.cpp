#include <bits/stdc++.h>
using namespace std;
string dg[] = {
	"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug",
	"sep", "oct", "nov", "dec"
};
string ten[] = {
	"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", 
	"syy", "lok", "mer", "jou"
};
int p[5];
string s;
map<string, int> mp;
map<string, int> pos;
void init() {
	for (int i = 0; i < 13; i++) {
		mp[ten[i]] = i;
		mp[dg[i]] = i;
		pos[ten[i]] = 1;
		pos[dg[i]] = 0;
	}
	p[0] = 1;
	for (int i = 1; i < 5; i++) {
		p[i] = p[i-1]*10;
	}
}
void solve() {
	getline(cin, s);
	if (s[0] >= '0' && s[0] <= '9') {
		int ret = 0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++) {
			ret += p[i]*(s[i]-'0');
		}
		vector<int> v;
		while (ret) {
			v.push_back(ret%13);
			ret /= 13;
		}
		if (!v.size()) {
			cout << dg[0] << endl;
			return;
		}
		if (v.size() == 2) {
			if (v[0] != 0) {
				cout << ten[v[1]] << ' ' << dg[v[0]] << endl;
			} else {
				cout << ten[v[1]] << endl;
			}
		} else {
			cout << dg[v[0]] << endl;
		}
	} else {
		stringstream ss;
		ss << s;
		string t;
		vector<string> v;
		int a[2] = {0, 0};
		while (ss >> t) {
			a[pos[t]] = mp[t];
		}
		cout << a[1]*13 + a[0] << endl;
	}
}
int main() {
	init();
	//std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	getchar();
	while (T--) {
		solve();
	}
	return 0;
}

