#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
unordered_set<string>s;
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	string name, log;
	for (int i = 0; i < n; i++) {
		cin >> name >> log;
		if (log == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	vector<string>ret(s.begin(), s.end());
	sort(ret.begin(), ret.end(), greater<string>());
	for (auto &c : ret)
		cout << c << '\n';
	return 0;
}