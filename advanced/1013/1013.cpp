#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
const int N = 1100;
int fa[N];
int Find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}
bool combine(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) {
        return 0;
    }
    fa[x] = y;
    return 1;
}
vector<pii> e;
int main(){
    int n, m, k, u, v, t;
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        scanf("%d%d", &u, &v);
        e.push_back(pii(u, v));
    }
    while (k--) {
        scanf("%d", &t);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (auto i: e) {
            if (i.X == t || i.Y == t) {
                continue;
            }
            combine(i.X, i.Y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i == t) {
                continue;
            }
            for (int j = i+1; j <= n; j++) {
                if (j == t) {
                    continue;
                }
                ans += combine(i, j);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
