#include <bits/stdc++.h>
using namespace std;
double solve() {
	double a, b, c;
	cin >> a >> b >> c;
	if (a > b && a > c) {
		printf("W ");
		return a;
	}
	if (b > a && b > c) {
		printf("T ");
		return b;
	}
	printf("L ");
	return c;
}
int main() {
	double r = 1.0;
	for (int i = 0; i < 3; i++)
		r *= solve();
	printf("%.2f\n", (r*0.65-1.0)*2.0);
	return 0;
}