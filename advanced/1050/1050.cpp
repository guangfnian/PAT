#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
char s[N], a[N];
bool vis[128];
int main() {
	gets(s);
	gets(a);
	int ls = strlen(s), la = strlen(a);
	for (int i = 0; i < la; i++)
		vis[a[i]] = 1;
	for (int i = 0; i < ls; i++)
		if (!vis[s[i]])
			putchar(s[i]);
	puts("");
	return 0;
}