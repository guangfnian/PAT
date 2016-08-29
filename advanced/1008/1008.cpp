#include <bits/stdc++.h>
using namespace std;
int main() {
	int pos = 0, n, k, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		if (k > pos) {
			ans += (k-pos)*6;
		} else {
			ans += (pos-k)*4;
		}
		ans += 5;
		pos = k;
	}
	printf("%d\n", ans);
	return 0;
}