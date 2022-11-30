#include <iostream>
using namespace std;
int A, B, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	cin >> C;
	A += C / 60;
	B += C % 60;
	if (B >= 60) {
		B -= 60;
		A++;
	}
	if (A >= 24)
		A %= 24;
	cout << A << " " << B;
	return 0;
}