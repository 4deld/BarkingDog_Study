#include<bits/stdc++.h>
using namespace std;
int ans, cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int>rzcnt; //razer count of each bar
	//suppose stack s
	char in;
	string iinn;
	bool r = true; //true - razer
	cin >> iinn;
	int len = iinn.length();
	for (int y = 0; y < len; y++) {
		in = iinn[y];
		bool ss = rzcnt.empty(); //empty ... return 1
		if (ss) {
			rzcnt.push_back(0); //first, suppose bar
			r = true;
		}
		else { //s.top == '('
			if (in == '(') {
				r = true;
				rzcnt.push_back(0);
			}
			else if (r) { //razer
				rzcnt.pop_back();
				for (int i = 0; i < rzcnt.size(); i++)
					rzcnt[i]++;
				r = false;
			}
			else { //in == ')'
				ans += rzcnt.back() + 1;
				rzcnt.pop_back();
			}
		}
	}
	cout << ans;
	return 0;
}