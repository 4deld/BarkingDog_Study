#include<bits/stdc++.h>
using namespace std;

int board[200][200][200];
int  dist[200][200][200];
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,0,0,0,1,-1 };
int dz[6] = { 0,1,0,-1,0,0 };

int n, m, h, mx;
queue<tuple<int, int, int>>q;

void BFS() {

	while (!q.empty()) {

		tuple<int, int,int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>((cur)) + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz<0 || nz>=h)
				continue;
			if (dist[nx][ny][nz] != -1 || board[nx][ny][nz] == -1)
				continue;
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nx,ny,nz });
		}
		/*for (int k = 0; k < h; k++) {
			for (int j = 0; j < m; j++) {
				for (int i = 0; i < n; i++) {
					cout << dist[i][j][k] << ' ';
				}
				cout << '\n';
			}

		}
		cout << '\n';*/
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int k = 0; k < h; k++)
		for (int j = 0; j < m; j++)
			for (int i = 0; i< n; i++)
				dist[i][j][k] = -1;

	for (int k = 0; k < h; k++){
		for (int j = 0; j < m; j++){
			for (int i = 0; i < n; i++){
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push({ i,j,k });
					dist[i][j][k] = 0;
				}
			}
		}
	}

	BFS();

	for (int k = 0; k < h; k++) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				mx = max(dist[i][j][k], mx);
				if (dist[i][j][k] == -1 && board[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << mx;
	return 0;
}