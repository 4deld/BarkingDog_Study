//���̰� n�� �迭���� �� ���Ҹ� ���ؼ� 100�� �Ǵ� ��찡 ������ 1 ������ 0 ��ȯ
//sol 1) ������� ������� ���������� �̿��ϸ� O(N^2)
//sol 2) �Ʒ��� ���� ������� O(N) ����

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