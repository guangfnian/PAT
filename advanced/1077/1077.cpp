#include <bits/stdc++.h>
using namespace std;
char s[110][300];
int l[110];
int main()
{
	int n, ans = 0, mx = 500;
	scanf("%d", &n);
	gets(s[0]);
	for (int i = 0; i < n; i++) {
		gets(s[i]);
		l[i] = strlen(s[i]);
		mx = min(mx, l[i]);
	}
	for (int i = 1; i <= mx; i++) {
		int f = 1;
		for (int j = 1; j < n; j++) {
			if (s[j][l[j]-i] != s[j-1][l[j-1]-i]) {
				f = 0;
				break;
			}
		}
		if (!f) break;
		ans = i;
	}
	if (!ans) puts("nai");
	else {
		int pos = ans;
		while (s[0][l[0]-pos] == ' ')
			pos--;
		for (int i = pos; i > 0; i--)
			putchar(s[0][l[0]-i]);
		puts("");
	}
	return 0;
}