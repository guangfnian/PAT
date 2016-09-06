#include <bits/stdc++.h>
using namespace std;
const int N = 90;
char a[N], b[N];
bool vis[128];
int main() {
	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b);
	for (int i = 0; i < lb; i++) {
		if (b[i] <= 'z' && b[i] >= 'a') {
			b[i] = b[i]-'a'+'A';
		}
		vis[b[i]] = 1;
	}
	for (int i = 0; i < la; i++) {
		if (a[i] <= 'z' && a[i] >= 'a') {
			a[i] = a[i]-'a'+'A';
		}
		if (!vis[a[i]]) {
			vis[a[i]] = 1;
			putchar(a[i]);
		}
	}
	puts("");
	return 0;
}