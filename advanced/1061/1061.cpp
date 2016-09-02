#include <bits/stdc++.h>
using namespace std;
const int N = 80;
char a[N], b[N];
char ans[][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	scanf("%s%s", a, b);
	int i;
	for (i = 0;; i++) {
		if (a[i] == b[i] && a[i] >= 'A' && a[i] < 'A'+7) {
			printf("%s ", ans[a[i]-'A']);
			break;
		}
	}
	for (i++ ;; i++) {
		if (a[i] == b[i]) {
			if (a[i] >= '0' && a[i] <= '9') {
				printf("0%d:", a[i]-'0');
				break;
			} else if (a[i] >= 'A' && a[i] <= 'N') {
				printf("%d:", a[i]-'A'+10);
				break;
			}
		}
	}
	scanf("%s%s", a, b);
	for (i = 0;; i++) {
		if (a[i] == b[i] && ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))) {
			if (i < 10) {
				printf("0%d", i);
			} else {
				printf("%d", i);
			}
			break;
		}
	}
	puts("");
	return 0;
}