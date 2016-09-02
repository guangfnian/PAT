#include <bits/stdc++.h>
using namespace std;
void toStr(int x, char *s) {
	s[3] = x%10 + '0';
	s[2] = x/10%10 + '0';
	s[1] = x/100%10 + '0';
	s[0] = x/1000%10 + '0';
}
int toInt(char *s) {
	return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + s[3]-'0';
}
void solve() {
	char a[4], b[4], c[4];
	int x, y, z;
	scanf("%d", &x);
	toStr(x, a), toStr(x, b);
	sort(a, a+4, greater<char>());
	sort(b, b+4);
	if (strcmp(a, b) == 0) {
		printf("%s - %s = 0000\n", a, b);
		return;
	}
	while (1) {
		toStr(x, a), toStr(x, b);
		sort(a, a+4, greater<char>());
		sort(b, b+4);
		x = toInt(a), y = toInt(b);
		x -= y;
		toStr(x, c);
		printf("%s - %s = %s\n", a, b, c);
		if (x == 6174) {
			return;
		}
	}
}
int main()
{
	solve();
	return 0;
}