#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll c) {
	if (b == 1) //base condition
		return a%c; //consider a>c
	ll v = power(a, b/2, c);
	v = v * v % c; 
	if (b % 2)
		return v * a % c;
	else
		return v;
}

int main() { 
	ll a, b, c;

	cin >> a >> b >> c;
	cout<<power(a, b, c);
	return 0;
}