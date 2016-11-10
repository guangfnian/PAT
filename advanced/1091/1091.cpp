#include <bits/stdc++.h>
using namespace std;
int mt[100][1300][1300], dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};
bool vis[100][1300][1300];
int ret, n, m, l, t;
struct node {
	int x, y, z;
	node(int x, int y, int z):x(x), y(y), z(z){}
};
void bfs(int x, int y, int z) {
	queue<node> q;
	q.push(node(x, y, z));
	vis[x][y][z] = 1;
	ret++;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
			if (nx < 0 || nx >= l || ny < 0 || ny >= n || nz < 0 || nz >= m || !mt[nx][ny][nz] || vis[nx][ny][nz]) {
				continue;
			}
			vis[nx][ny][nz] = 1;
			ret++;
			q.push(node(nx, ny, nz));
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &l, &t);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &mt[i][j][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!mt[i][j][k] || vis[i][j][k]) {
					continue;
				}
				ret = 0;
				bfs(i, j, k);
				if (ret >= t) {
					ans += ret;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

