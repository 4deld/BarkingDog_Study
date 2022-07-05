#include<bits/stdc++.h>
using namespace std;

char board[600][600];
int  dist[600][600];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

void BFS(int i, int j) {

	queue<pair<int, int>>q;
	q.push({ i,j });
	dist[i][j] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] != -1 || board[nx][ny] == '0')
				continue;

			dist[nx][ny] = dist[cur.first][cur.second]+1;
			q.push({ nx,ny });
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << dist[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		for (int j = 0; j < m; j++)
			board[i][j] = in[j];
	}
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}

	BFS(0, 0);

	cout << dist[n - 1][m - 1];
	return 0;
}