#include<bits/stdc++.h>
using namespace std;
int tmp,ans;
char ch;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char>s;
	stack<int> d; //'(' -> 0 / '[' -> 1
	string in;
	cin >> in;

	for (int i = 0; i < in.length(); i++) {
		ch = in[i];
		bool ss = s.empty();

		if (ss) {
			if (ch == ')' || ch == ']') {
				cout << 0;
				return 0;
			}
			s.push(ch);
			if (ch == '(')
				d.push(0);
			else
				d.push(1);
		}

		else {
			if (ch == '(') {
				s.push(ch);
				d.push(0);
			}
			else if (ch == '[') {
				s.push(ch);
				d.push(1);
			}
			else if (ch == ')') {
				if (s.top() == '(') {
					s.pop();
					if (d.top() == 0) {
						d.pop();
						d.push(2);
					}
					else {
						tmp = 0;
						while (d.top() != 0) {
							tmp += d.top();
							d.pop();
						}
						d.pop();
						d.push(tmp * 2);
					}

				}
				else {
					cout << 0;
					return 0;
				}
			}
			else { // ']'
				if (s.top() == '[') {
					s.pop();
					if (d.top() == 1) {
						d.pop();
						d.push(3);
					}
					else {
						tmp = 0;
						while (d.top() != 1) {
							tmp += d.top();
							d.pop();
						}
						d.pop();
						d.push(tmp * 3);
					}
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
	}

	if (!s.empty()) {
		cout << 0;
	}
	else {
		while (!d.empty()) {
			ans += d.top();
			d.pop();
		}
		cout << ans;
	}
	return 0;
}