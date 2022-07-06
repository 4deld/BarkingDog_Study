//�˰��� ����
// ó���� dist�� -1�� �ʱ�ȭ (visited�� �������� �ʾƵ� ��)
// board������ �ʱ� Joe, Fire ��ġ�� ������ �ʴ� ���� ��ġ�� ����
// ���� ���ϴ� Joe, Fire�� dist���� ����
// Joe�� Fire�� ���� ���������� ť�� ���� ������ Joe ���� Fire�̱� ������
// ó���� ��� Joe�� Fire�� �ְ� ���� Joe�� ���� 1���� ���� ���� �̿�
// Joe�� -1(not visited and not fire)�̰� ���� �ƴ� ĭ�� �� �� �ְ�
// Fire�� not fire�� ĭ�� ���� �ƴ� ĭ�� �� �� �ִ�
// �׷��� dist[cur.first][cur.second] �̰� ť�� ���� ĭ�ε� �̰� 0�̻��̸�
// Joe Fire ���� Joe�� ���� ���̰� 1���� ���� ��
// �׷��� ���⼭ board�� ���ڶ��� �ִ��� �����ϸ� �ȴ�
//

// ���� 1 - ���� ���� - �޸� �ʰ�
// �̹� Fire�� ĭ�� �������� �ʰų� Joe�� visited�� üũ���� �ʾƼ� �޸� �ʰ��� ����
// 256MB�� �Ѿ �� �˰� �̻��� �� ���� �ߴµ� �˰��� ���ѷ�������....
// 
// ���� 2 - nx, ny, r, c �򰥸� - ��Ÿ�� ����
// �׳� row�� column �ް�
// board[row][column] �ڸ��� �������
// board[nx][ny]
// �׳� row nx, column ny ���� 
//

// ����
// �̰� �ּҽð��� ������ �� �ִ��� ����� �ôµ�
// bfs�� ������ �� ť�� �� �͵� �� ���� �ٷ� �������ڸ���(Joe Fire Joe����) 
// return �ϴϱ� �ּҽð����� ������ ..?

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