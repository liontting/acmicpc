#include <iostream>
using namespace std;
int n, num, sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
	}
	cout << sum;
	return 0;
}