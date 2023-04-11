#include <iostream>
using namespace std;
int T, C, q, d, n, p;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> C;
		q = C / 25;
		C -= C / 25 * 25;
		d = C / 10;
		C -= C / 10 * 10;
		n = C / 5;
		C -= C / 5 * 5;
		p = C;
		cout << q << " " << d << " " << n << " " << p << "\n";
	}
	return 0;
}