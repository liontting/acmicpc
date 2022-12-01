#include <iostream>
#include <algorithm>
using namespace std;
char num[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int idx = 0;
	cin >> num;
	for (; num[idx]; idx++);
	sort(num, num + idx);
	for (int i = idx - 1; i >= 0; i--)
		cout << num[i];
	return 0;
}