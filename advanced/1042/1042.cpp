#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char c[] = {'S', 'H', 'C', 'D', 'J'};
int trs[55];
vector<int> a(55), b(55);
int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 1; i < 55; i++) {
		scanf("%d", &trs[i]);
		a[i] = i;
	}
	while (k--) {
		for (int i = 1; i < 55; i++) {
			b[trs[i]] = a[i];
		}
		a = b;
	}
	printf("%c%d", c[(a[1]-1)/13], a[1] % 13 ? a[1] % 13: 13);
	for (int i = 2; i < 55; i++) {
		printf(" %c%d", c[(a[i]-1)/13], a[i] % 13 ? a[i] % 13: 13);
	}
	puts("");
	return 0;
}