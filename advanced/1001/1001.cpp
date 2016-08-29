#include <bits/stdc++.h>
using namespace std;
int p[9];
int main()
{
    p[0] = 1;
    for (int i = 1; i <= 8; i++)
        p[i] = p[i-1]*10;
    int a, b, c, l;
    while(~scanf("%d%d", &a, &b)) {
        c = a+b;
        if (c == 0) {
            puts("0");
            continue;
        }
        if (c < 0) {
            putchar('-');
            c = -c;
        }
        l = log10(c);
        for (int i = l; i >= 0 ;i--) {
            int k = (c / p[i]) % 10;
            printf("%d", k);
            if (i % 3 == 0 && i)
                putchar(',');
        }
        puts("");
    }
    return 0;
}