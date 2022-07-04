#include<bits/stdc++.h>
using namespace std;
int ans, cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char>s;
	char in;
	string iinn;
	bool r = true; //true - razer
	cin >> iinn;
	int len = iinn.length();
	for (int y = 0; y < len; y++) {
		in = iinn[y];
		bool ss = s.empty(); //empty ... return 1
		if (ss) {
			s.push('(');
			r = true;
		}
		else { //s.top == '('
			if (in == '(') {
				r = true;
				s.push('(');
			}
			else { //in == ')'
				
				if (r) { //razer
					s.pop();
					r = false;
					ans += s.size();
				}
				else {
					s.pop();
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}