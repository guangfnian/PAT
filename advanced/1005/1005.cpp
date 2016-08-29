#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char s[N];
char ans[][10] = {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"
};
int main() {
	scanf("%s", s);
	int l = strlen(s), sum = 0;
	for (int i = 0; i < l; i++)
		sum += s[i]-'0';
	stack<int> S;
	while (sum > 0) {
		S.push(sum%10);
		sum /= 10;
	}
	if (S.empty())
		S.push(0);
	printf("%s", ans[S.top()]);
	S.pop();
	while (!S.empty()) {
		printf(" %s", ans[S.top()]);
		S.pop();
	}
	puts("");
	return 0;
}