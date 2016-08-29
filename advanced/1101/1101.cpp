#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], mx[N], mn[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > mx[i-1])
            mx[i] = a[i];
        else
            mx[i] = mx[i-1];
    }
    mn[n+1] = 0x3f3f3f3f;
    for (int i = n; i > 0; i--)
    {
        if (a[i] < mn[i+1])
            mn[i] = a[i];
        else
            mn[i] = mn[i+1];
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (a[i] >= mx[i-1] && a[i] <= mn[i+1])
            ans.push_back(a[i]);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d%s", ans[i], (i == ans.size()-1? "\n": " "));
    if (ans.size() == 0)
        puts("");
    return 0;
}