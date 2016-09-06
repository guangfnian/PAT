#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int mx = 0;
string ans;
int main() {
	string s, t;
	getline(cin, s);
	int p = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 'Z' && s[i] >= 'A') {
			s[i] = s[i] - 'A' + 'a';
		} else if (!((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0'))) {
			s[i] = ' ';
		}
	}
	stringstream ss;
	ss << s;
	while (ss >> t) {
		mp[t]++;
	}
	for (auto i: mp) {
		if (i.second > mx) {
			mx = i.second;
			ans = i.first;
		} else if (i.second == mx) {
			ans = min(ans, i.first);
		}
	}
	cout << ans << ' ' << mx << endl;
	return 0;
}