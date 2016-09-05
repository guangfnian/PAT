#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int N = 1100;
vector<int> f[N];
bool vis[N];
int n, l;
int bfs(int st) {
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    vis[st] = 1;
    queue<P> que;
    que.push(P(st, 0));
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        if (y > l) {
            continue;
        }
        cnt++;
        for (int i: f[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                que.push(P(i, y+1));
            }
        }
    }
    return cnt-1;
}
int main() {
    int m, t;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &t);
            f[t].push_back(i);
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        printf("%d\n", bfs(t));
    }
    return 0;
}