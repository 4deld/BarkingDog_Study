#include<bits/stdc++.h>
using namespace std;
int n;

void move(int a, int b, int k) { //from a to b 
    if (k == 0)
        return;
    move(a, 6 - a - b, k - 1);
    cout << a << ' ' << b << '\n';
    move(6 - a - b, b, k - 1);
}

int main() {
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    move(1, 3, n);
    return 0;
}