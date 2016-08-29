#include <bits/stdc++.h>
using namespace std;
char op[15] = {"0123456789ABC"};
void solve(int x)
{
    string s;
    while (x >= 13)
    {
        s = op[x%13] + s;
        x /= 13;
    }
    s = op[x] + s;
    while (s.size() < 2)
        s = op[0] + s;
    cout << s;
}
int main()
{
    int a;
    printf("#");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a);
        solve(a);
    }
    puts("");
	return 0;
}