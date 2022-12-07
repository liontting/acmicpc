#include <iostream>
using namespace std;
int T, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int n = 1;
		for (int i = 0; i < b; i++) {
			n *= a;
			n %= 10;
		}
		if (n == 0)
			n = 10;
		cout << n << "\n";
	}
	return 0;
}