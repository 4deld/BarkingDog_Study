#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int pre[MAX], nxt[MAX], n;
int unused = 1, cursor;
char res[MAX], c, s;
void insert(int ad, char u) { //res[ad] 값의 다음 순서가 u가 됨
	res[unused]= u;
	if (nxt[ad] != -1)
		pre[nxt[ad]] = unused;
	pre[unused] = ad;
	nxt[unused] = nxt[ad];
	cursor = nxt[ad] = unused;
	
	unused++;
}
void erase(int ad) {
	if (nxt[ad] != -1) {
		pre[nxt[ad]] = pre[ad];
	}
	nxt[pre[ad]] = nxt[ad];
	cursor = pre[ad];
}
void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << res[cur];
		cur = nxt[cur];
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	fill(pre, pre + MAX, -1);
	fill(nxt, nxt + MAX, -1);
	string input;
	cin >> input;

	for (auto c : input)
		insert(cursor++, c);
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (pre[cursor] != -1)
				cursor = pre[cursor];
		}
		else if (c == 'D') {
			if (nxt[cursor] != -1)
				cursor = nxt[cursor];
		}
		else if (c == 'B') {
			if (pre[cursor]!=-1) {
				erase(cursor);
			}
		}
		else {
			cin >> s;
			insert(cursor, s);
		}
		

	}
	traverse();

	return 0;
}