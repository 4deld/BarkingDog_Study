#include<bits/stdc++.h>
using namespace std;

int board[2000][2000];
int  dist[2000][2000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m,mx;
queue<pair<int, int>>q;

void BFS() {

	while (!q.empty()) {

		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] != -1 || board[nx][ny] == -1)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second]+1;
			q.push({ nx,ny });
			
		}

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = max(dist[i][j], mx);
			if (dist[i][j] == -1 && board[i][j]==0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << mx;
	return 0;
}