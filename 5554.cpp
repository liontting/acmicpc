#include <iostream>
using namespace std;
int second[5], x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		cin >> second[i];
		x += second[i];
	}
	y = x % 60;
	x = x / 60;
	cout << x << "\n" << y;
	return 0;
}