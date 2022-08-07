#include<bits/stdc++.h>
using namespace std;

int n, m, a[10];
bool check[10];
void f(int l) {
	if (l == m) {
		for (int i = 0; i < l; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i < n + 1; i++) {
			if (!check[i]) {
				a[l] = i;
				check[i] = true;
				f(l + 1);
				check[i] = false;
			}
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	f(0);
	return 0;
}