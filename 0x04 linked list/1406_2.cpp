#include<bits/stdc++.h>
using namespace std;
int cursor, n;
char c, s;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	list<char> L;
	string input;

	cin >> input;
	for (auto c : input)
		L.push_back(c);
	auto cursor = L.end();
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (cursor != L.begin())	
				cursor--;
		}
		else if (c == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (c == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else {
			cin >> s;
			L.insert(cursor, s);
		}
	}
	for (auto i : L)
		cout << i;
	return 0;
}