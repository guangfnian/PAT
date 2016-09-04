#include <bits/stdc++.h>
using namespace std;
const int N = 550, inf = 0x3f3f3f3f;
struct edge{
    int to, d, c;
    edge(int a = 0, int b = 0, int c = 0): to(a), d(b), c(c){}
};
vector<edge> e[N];
int dis[N], cost[N];
bool vis[N];
void spfa(int st) {
    queue<int> que;
    que.push(st);
    vis[st] = 1;
    dis[st] = cost[st] = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (auto nxt: e[t]) {
            if (dis[t] + nxt.d < dis[nxt.to]) {
                dis[nxt.to] = dis[t] + nxt.d;
                cost[nxt.to] = cost[t] + nxt.c;
                if (!vis[nxt.to]) {
                    vis[nxt.to] = 1;
                    que.push(nxt.to);
                }
            } else if (dis[t] + nxt.d == dis[nxt.to] && cost[nxt.to] > cost[t] + nxt.c) {
                cost[nxt.to] = cost[t] + nxt.c;
                if (!vis[nxt.to]) {
                    vis[nxt.to] = 1;
                    que.push(nxt.to);
                }
            }
        }
        vis[t] = 0;
    }
}
void dfs(int rt, int p, int tar) {
    if (p == tar) {
        printf("%d ", p);
        return;
    }
    for (auto i: e[p]) {
        if (i.to == rt) {
            continue;
        }
        if (dis[p] - dis[i.to] == i.d && cost[p] - cost[i.to] == i.c) {
            dfs(p, i.to, tar);
            printf("%d ", p);
            return;
        }
    }
}
int main() {
    fill(dis, dis+N, inf);
    fill(cost, cost+N, inf);
    int n, m, st, ed, u, v, a, b;
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    while (m--) {
        scanf("%d%d%d%d", &u, &v, &a, &b);
        e[u].push_back(edge(v, a, b));
        e[v].push_back(edge(u, a, b));
    }
    spfa(st);
    dfs(-1, ed, st);
    printf("%d %d\n", dis[ed], cost[ed]);
    return 0;
}