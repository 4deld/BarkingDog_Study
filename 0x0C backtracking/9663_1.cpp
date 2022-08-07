//행은 check 판단할 필요가 없음 왜냐하면 row를 계속 +1해서 넘겨주기 때문에
//같은 행에 들어갈 수가 없다
//그래서 같은 열, 대각선(2방향)을 check해주고 돌리고 check를 해제해준다
//check를 bool이 아니라 int로 한 것은 true, false로 하게 되면
//칸의 상태를 2가지로만 표현할 수밖에 없다
//그래서 2개 이상의 Queen이 같은 칸을 공격할 수 있을 때 하나의 Queen의 check를 해제해버리면
//남은 하나의 Queen은 공격할 수 있는데 공격할 수 없다고 false로 잘못 표기하게 된다
//그래서 값을 칸을 공격할 수 있는 Queen의 개수로 해서 ++,--로 하면 제대로 표기할 수 있다
#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int check[20][20];
void Q(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int j = 0; j < n; j++) {
		if (!check[row][j]) {
			for (int i = row; i < n; i++) {
				check[i][j]++;
			}
			int y = row;
			int x = j;
			while (y<n && x<n) {
				check[y++][x++]++;
			}
			y = row;
			x = j;
			while (y<n && x>-1) {
				check[y++][x--]++;
			}
			Q(row + 1);
			for (int i = row; i < n; i++) {
				check[i][j]--;
			}
			y = row;
			x = j;
			while (y < n && x < n) {
				check[y++][x++]--;
			}
			y = row;
			x = j;
			while (y<n && x>-1) {
				check[y++][x--]--;
			}
		}
	}
	return;

}
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	Q(0);
	cout << cnt;
	return 0;
}