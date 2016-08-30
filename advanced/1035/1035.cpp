#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
vector<pss> v;
int main() {
	int n;
	string name, pass;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> name >> pass;
		bool f = 0;
		for (int i = 0; i < pass.size(); i++) {
			switch(pass[i]) {
				case '1': pass[i] = '@';f=1;break;
				case '0': pass[i] = '%';f=1;break;
				case 'O': pass[i] = 'o';f=1;break;
				case 'l': pass[i] = 'L';f=1;break;
			}
		}
		if (f) v.push_back(pss(name, pass));
	}
	if (v.size() == 0) {
		if (n == 1) puts("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified\n", n);
	} else {
		printf("%d\n", v.size());
		for (auto s: v)
			cout << s.first << ' ' << s.second << endl;
	}
	return 0;
}