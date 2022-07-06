//51번 줄에서 FireD[nx][ny]!=-1이거를 검사를 안했어서 WA 나왔는데 왜인지 모르겠다


#include<bits/stdc++.h>
using namespace std;
int r, c;
string board[1007];
int FireD[1007][1007];
int JoeD[1007][1007];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1, 0 };

string ans = "IMPOSSIBLE";
queue<pair<int, int>>q;
queue<pair<int, int>>jq;

void FireBFS() {
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] == '#' || FireD[nx][ny] !=-1)
				continue;
			FireD[nx][ny] = FireD[cur.first][cur.second]+1;

			q.push({ nx,ny });
		}


	}
}

void JoeBFS() {
	while (!jq.empty()) {
		pair<int, int>cur = jq.front();
		jq.pop();
		if ((cur.first == 0 || cur.second == 0 || cur.first == r - 1 || cur.second == c - 1)) {
			ans = to_string(JoeD[cur.first][cur.second] + 1);
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] == '#' || (FireD[nx][ny] <= JoeD[cur.first][cur.second] + 1 && FireD[nx][ny]!=-1) || JoeD[nx][ny] != -1)
				continue;
			JoeD[nx][ny] = JoeD[cur.first][cur.second] + 1;

			jq.push({ nx,ny });
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		fill(FireD[i], FireD[i] + c, -1);
	}
	for (int i = 0; i < r; i++) {
		fill(JoeD[i], JoeD[i] + c, -1);
	}
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				q.push({ i,j });
				FireD[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				jq.push({ i,j });
				JoeD[i][j] = 0;
			}
		}
	}

	FireBFS();

	JoeBFS();

	cout << ans;

	return 0;
}