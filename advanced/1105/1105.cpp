#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mat[1100][1100], a[100010];
int N, n, m;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, nxt[] = {2, 3, 1, 0};
int main() {
	scanf("%d", &N);
	for (int i = sqrt(N); ; i--) {
		if (N % i == 0) {
			m = i;
			n = N / i;
			break;
		}
	}
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a+N, greater<int>());
	memset(mat, -1, sizeof(mat));
	int x = 1, y = 1, dir = 0;
	for (int i = 0; i < N; i++) {
		mat[x][y] = a[i];
		int nx = x+dx[dir], ny = y+dy[dir];
		if (nx < 1 || nx > n || ny < 1 || ny > m || mat[nx][ny] != -1) {
			dir = nxt[dir];
			nx = x+dx[dir], ny = y+dy[dir];
		}
		x = nx, y = ny;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", mat[i][1]);
		for (int j = 2; j <= m; j++) {
			printf(" %d", mat[i][j]);
		}
		puts("");
	}
	return 0;
}