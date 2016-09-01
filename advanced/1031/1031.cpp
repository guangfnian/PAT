#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char s[N];
char mt[1100][1100];
int main()
{
	scanf("%s", s);
	int l = strlen(s), n = (l+2)/3, m = (l+2)/3 + (l+2) % 3;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mt[i][j] = ' ';
	int pos = 0;
	for (int i = 0; i < n; i++)
		mt[i][0] = s[pos++];
	for (int i = 1; i < m; i++)
		mt[n-1][i] = s[pos++];
	for (int i = n-2; i >= 0; i--)
		mt[i][m-1] = s[pos++];
	for (int i = 0; i < n; i++)
		puts(mt[i]);
	return 0;
}