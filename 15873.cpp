#include <iostream>
using namespace std;

int main() {
	int A, B, n;
	cin >> n;
	if (n > 99) {
		if (n % 100 < 10) {
			A = 10;
			B = n % 100;
		}
		else {
			A = n / 100;
			B = 10;
		}
	}
	else {
		A = n / 10;
		B = n % 10;
	}
	cout << A + B;
	return 0;
}
