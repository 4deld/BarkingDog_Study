//알고리즘 구상
// 처음에 dist를 -1로 초기화 (visited를 설정하지 않아도 됨)
// board에서는 초기 Joe, Fire 위치와 변하지 않는 벽의 위치만 참조
// 이후 변하는 Joe, Fire는 dist에서 관리
// Joe와 Fire는 같이 움직이지만 큐에 들어가는 순서는 Joe 다음 Fire이기 때문에
// 처음에 모든 Joe와 Fire를 넣고 다음 Joe가 오면 1분이 지난 것을 이용
// Joe는 -1(not visited and not fire)이고 벽이 아닌 칸만 갈 수 있고
// Fire는 not fire인 칸과 벽이 아닌 칸을 갈 수 있다
// 그래서 dist[cur.first][cur.second] 이게 큐에 들어온 칸인데 이게 0이상이면
// Joe Fire 다음 Joe가 들어온 것이고 1분이 지난 것
// 그래서 여기서 board의 끝자락에 있는지 조사하면 된다
//

// 오답 1 - 무한 루프 - 메모리 초과
// 이미 Fire인 칸을 배제하지 않거나 Joe의 visited를 체크하지 않아서 메모리 초과가 났다
// 256MB를 넘어간 줄 알고 이상한 짓 많이 했는데 알고보니 무한루프였다....
// 
// 오답 2 - nx, ny, r, c 헷갈림 - 런타임 에러
// 그냥 row와 column 받고
// board[row][column] 자리로 기억하자
// board[nx][ny]
// 그냥 row nx, column ny 대응 
//

// 질문
// 이게 최소시간을 보장할 수 있는지 고민해 봤는데
// bfs를 돌리고 그 큐에 들어간 것들 중 벽에 바로 도달하자마자(Joe Fire Joe에서) 
// return 하니까 최소시간이지 않을까 ..?

#include<bits/stdc++.h>
using namespace std;
int r, c;
string board[1007];
int dist[1007][1007];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1, 0};
string ans="IMPOSSIBLE";
queue<pair<int, int>>q;

void BFS() {
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();

		if (dist[cur.first][cur.second] >= 0) {
			if ((cur.first == 0 || cur.second == 0 || cur.first == r - 1 || cur.second == c - 1)) {
				ans = to_string(dist[cur.first][cur.second]+1);
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (board[nx][ny] == '#' || dist[nx][ny]!=-1)
					continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}

		else {
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (board[nx][ny] == '#' || dist[nx][ny] == -2)
					continue;
				dist[nx][ny] = -2;

				q.push({ nx,ny });
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		fill(dist[i], dist[i] + c, -1);
	}

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				q.push({ i,j });
				dist[i][j] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				q.push({ i,j });
				dist[i][j] = -2;
			}
		}
	}

	BFS();

	cout << ans;

	return 0;
}