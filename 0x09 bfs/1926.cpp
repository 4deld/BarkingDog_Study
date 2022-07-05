#include<bits/stdc++.h>
using namespace std;

int board[600][600];
bool v[600][600];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, paintcnt, mx;

void BFS(int i, int j) {
	int cnt = 0;
	paintcnt++;

	queue<pair<int, int>>q;
	v[i][j] = 1;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (v[nx][ny] == 1 || board[nx][ny] == 0)
				continue;
			v[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (cnt > mx)
		mx = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0 && board[i][j] == 1) {
				BFS(i, j);
			}
		}
	}

	cout << paintcnt << '\n' << mx;

	return 0;
}