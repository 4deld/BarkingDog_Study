#include<bits/stdc++.h>
using namespace std;
int n,r,c;

int func(int n, int r, int c) {
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (r > half && c > half) //4
        return 3 * half * half + func(n - 1, r - half, c - half);
    else if (r > half) //3
        return 2 * half * half + func(n - 1, r - half, c);
    else if (c > half) //2
        return 1 * half * half + func(n - 1, r, c - half);
    else //1
        return func(n - 1, r, c);
}

int main() {
    cin >> n >> r >> c;
    cout<<func(n, r+1, c+1);
    return 0;
}