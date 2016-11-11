#include <bits/stdc++.h>
using namespace std;
char dw[][5] = {
	"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"
};
char dg[][5] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
int main() {
	char s[15];
	scanf("%s", s);
	int l = strlen(s);
	reverse(s, s+l);
	vector<char*> v;
	int p = 0;
	while (p < l) {
		if (s[p] == '-') {
			v.push_back("Fu");
		} else {
			if (s[p] != '0') {
				if (p) {
					v.push_back(dw[p]);
				}
				v.push_back(dg[s[p] - '0']);
			} else if (p == 4) {
				v.push_back("Wan");
			} else {
				v.push_back("ling");
				while (p < l && s[p] == '0') {
					if (p == 4) {
						v.push_back("Wan");
					}
					p++;
				}
				p--;
			}
		}
		p++;
	}
	reverse(v.begin(), v.end());
	while (v.size() > 1 && strcmp(*(v.end()-1), "ling") == 0) {
		v.erase(v.end()-1);
	}
	printf("%s", v[0]);
	for (int i = 1; i < v.size(); i++) {
		printf(" %s", v[i]);
	}
	puts("");
	return 0;
}

