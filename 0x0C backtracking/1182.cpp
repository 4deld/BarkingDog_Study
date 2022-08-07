#include<bits/stdc++.h>
using namespace std;

int n, s, a[50], cnt;
void f(int idx,int t) {
	if (idx==n) {
		if (t == s)
			cnt++;
		return;
	}
	f(idx + 1,t);
	f(idx + 1,t+a[idx]);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	f(0,0);
	if (s == 0)
		cnt--;
	cout << cnt;
	return 0;
}