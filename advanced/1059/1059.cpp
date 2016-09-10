#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int w[110000] = {2, 3, 5, 7, 11, 13};
bool isPrime(int n) {
	int k = sqrt(n);
	for (int i = 0; w[i] <= k; i++) {
		if (n % w[i] == 0) {
			return 0;
		}
	}
	return 1;
}
void init(int N) {
	int n = 6, k = sqrt(N);
	for (int i = 17; i <= k; i++) {
		if (isPrime(i)) {
			w[n++] = i;
		}
	}
}
vector<pii> ans;
int main() {
	int n;
	scanf("%d", &n);
	if (n < 4) {
		printf("%d=%d\n", n, n);
		return 0;
	}
	init(n);
	int cnt, pos = 0, tmp = n;
	while (tmp > 1) {
		cnt = 0;
		while (tmp % w[pos] != 0) {
			pos++;
		}
		while (tmp % w[pos] == 0) {
			tmp /= w[pos];
			cnt++;
		}
		ans.push_back(pii(w[pos], cnt));
	}
	printf("%d=%d", n, ans[0].first);
	if (ans[0].second > 1) {
		printf("^%d", ans[0].second);
	}
	for (int i = 1; i < ans.size(); i++) {
		printf("*%d", ans[i].first);
		if (ans[i].second > 1) {
			printf("^%d", ans[i].second);
		}
	}
	puts("");
	return 0;
}