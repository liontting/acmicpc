#include <iostream>
using namespace std;
int A, B, C, D, hour, minute, second;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	cin >> D;
	D = D % 86400;
	second = D % 60;
	minute = D / 60;
	if (minute >= 60) {
		hour = minute / 60;
		minute = minute % 60;
	}
	A += hour;
	B += minute;
	C += second;
	if (C >= 60) {
		B = B + (C / 60);
		C = C % 60;
	}
	if (B >= 60) {
		A = A + (B / 60);
		B = B % 60;
	}
	if (A >= 24) {
		A -= 24;
	}
	cout << A << " " << B << " " << C;
	return 0;
}