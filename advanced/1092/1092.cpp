#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
char s[N], a[N];
int cnt[128];
int main()
{
	scanf("%s%s", s, a);
	int ls = strlen(s), la = strlen(a);
	for (int i = 0; i < ls; i++)
		cnt[s[i]]++;
	int ans = 0, f = 1;
	for (int i = 0; i < la; i++) {
		if (!cnt[a[i]]) {
			ans++;
			f = 0;
		} else {
			cnt[a[i]]--;
		}
	}
	if (f) {
		printf("Yes %d\n", ls-la);
	} else {
		printf("No %d\n", ans);
	}
	return 0;
}