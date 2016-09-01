#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int sum[N], x;
int main()
{
	int a, b, c, x, y, z, add = 0;
	scanf("%d.%d.%d%d.%d.%d", &a, &b, &c, &x, &y, &z);
	z += c;
	add = z / 29;
	z %= 29;
	y += b+add;
	add = y / 17;
	y %= 17;
	x += a+add;
	printf("%d.%d.%d\n", x, y, z);
	return 0;
}