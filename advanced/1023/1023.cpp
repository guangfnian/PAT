#include <bits/stdc++.h>
using namespace std;
char s[25], a[25];
int cnt[15];
void solve() {
	scanf("%s", s);
	int l = strlen(s);
	int add = 0;
	bool f = 1;
	a[l] = '\0';
	for (int i = l-1; i >= 0; i--) {
		int k = (s[i]-'0')*2 + add;
		a[i] = k%10 + '0';
		add = k/10;
	}
	if (add) {
		f = 0;
	}
	for (int i = 0; i < l; i++) {
		cnt[s[i]-'0']++;
		cnt[a[i]-'0']--;
	}
	for (int i = 0; i < 11; i++)
		if (cnt[i] != 0) {
			f = 0;
		}
	if (f) {
		puts("Yes");
		puts(a);
	} else {
		puts("No");
		if (add) printf("%d", add);
		puts(a);
	}
}
int main() {
	solve();
	return 0;
}