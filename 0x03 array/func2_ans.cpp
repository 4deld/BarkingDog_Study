//길이가 n인 배열에서 두 원소를 합해서 100이 되는 경우가 있으면 1 없으면 0 반환
//sol 1) 통상적인 방법으로 이중포문을 이용하면 O(N^2)
//sol 2) 아래와 같은 방법으로 O(N) 가능

#include<bits/stdc++.h>
using namespace std;
int n, arr[10000], freq[120];
int func2(int* arr, int n) {
	for (int* i = arr; i < arr + n; i++) {
		if (freq[100 - *i])
			return 1;
		freq[*i] = 1;
	}
	return 0;
}
int main() {
	cin >> n;
	for (int* i = arr; i < arr + n; i++)
		cin >> *i;
	cout << func2(arr, n);

	return 0;
}