//���� check �Ǵ��� �ʿ䰡 ���� �ֳ��ϸ� row�� ��� +1�ؼ� �Ѱ��ֱ� ������
//���� �࿡ �� ���� ����
//�׷��� ���� ��, �밢��(2����)�� check���ְ� ������ check�� �������ش�
//check�� bool�� �ƴ϶� int�� �� ���� true, false�� �ϰ� �Ǹ�
//ĭ�� ���¸� 2�����θ� ǥ���� ���ۿ� ����
//�׷��� 2�� �̻��� Queen�� ���� ĭ�� ������ �� ���� �� �ϳ��� Queen�� check�� �����ع�����
//���� �ϳ��� Queen�� ������ �� �ִµ� ������ �� ���ٰ� false�� �߸� ǥ���ϰ� �ȴ�
//�׷��� ���� ĭ�� ������ �� �ִ� Queen�� ������ �ؼ� ++,--�� �ϸ� ����� ǥ���� �� �ִ�
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