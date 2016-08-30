#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
char s[N];
int _mx = 1;
void solve(int l, int r) {
	for (int i = 0; l+i <= r; i++)
		if (s[l+i] != s[r-i])
			return;
	_mx = max(_mx, r-l+1);
}
int main()
{
	gets(s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		for (int j = i+_mx; j < l; j++)
			solve(i, j);
	}
	printf("%d\n", _mx);
	return 0;
}