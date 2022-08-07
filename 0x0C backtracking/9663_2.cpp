#include<bits/stdc++.h>
using namespace std;

int n, cnt;
bool ycheck[20];
bool diagonal_l[20];
bool diagonal_r[20];
void Q(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int j = 0; j < n; j++) {
		if (!ycheck[j] && !diagonal_l[row + j] && !diagonal_r[j - row + n - 1]) {
			ycheck[j]=true;
			diagonal_l[row + j]=true;
			diagonal_r[j - row + n - 1]=true;
			Q(row + 1);
			ycheck[j]=false;
			diagonal_l[row + j]=false;
			diagonal_r[j - row + n - 1]=false;
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