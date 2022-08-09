#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<string,int>um;
string s[100004];

int main() {
	cin.tie(0);
	int n,m;
	cin >> n>>m;
	string in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		s[i + 1] = in;
		um[in] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> in;
		if (isdigit(in[0])) {
			cout << s[stoi(in)]<<'\n';
		}
		else {
			cout << um[in]<<'\n';
		}
	}
	return 0;
}