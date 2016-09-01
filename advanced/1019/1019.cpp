#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	while (n >= b) {
		v.push_back(n % b);
		n /= b;
	}
	v.push_back(n);
	vector<int> y(v);
	reverse(y.begin(), y.end());
	int f = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != y[i]) {
			f = 0;
			break;
		}
	}
	puts((f ? "Yes": "No"));
	printf("%d", y[0]);
	for (int i = 1; i < y.size(); i++)
		printf(" %d", y[i]);
	puts("");
	return 0;
}