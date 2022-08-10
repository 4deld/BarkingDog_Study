#include<bits/stdc++.h>
using namespace std;
vector<int> failure(string& s) { //failure function
	vector<int> f(s.size(),0);
	int j = 0;

	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = f[j - 1];
		}

		if (s[i] == s[j]) {
			f[i] = ++j;
		}
	}

	return f;
}
int main() {
	string s, p;

	cin >> s >> p;
	vector<int>FF = failure(p);
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) {
			j = FF[j - 1];
		}
		if (s[i]==p[j]) {
			j++;
		}
		if (j == p.size()) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}