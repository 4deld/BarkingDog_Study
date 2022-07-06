#include<bits/stdc++.h>
using namespace std;
int n, k;
int d[100009];
int dx[3];
int main() {
	cin >> n >> k;
	queue<int>q;
	fill(d, d + 100009, -1);
	q.push(n);
	d[n] = 0;
	while ((d[k] == -1)) {
		int cur = q.front();
		q.pop();
		*dx = cur - 1;
		*(dx+1) = cur + 1;
		*(dx+2) = cur*2;
		for (int dir = 0; dir < 3; dir++) {
			int nx = dx[dir];
			if (nx < 0 || nx >= 100001 || d[nx]!=-1)
				continue;
			d[nx] = d[cur] + 1;
			q.push(nx);
		}
	}
	cout << d[k];
	return 0;
}
