#include <iostream>
using namespace std;
int T;
long long int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int check = 0;
		cin >> n;
		if (n == 0 || n == 1 || n == 2)
			cout << 2 << "\n";
		else {
			while (1) {
				for (long long int i = 2; i * i <= n; i++) {
					if (n % i == 0) {
						check = 1;
						break;
					}
				}
				if (!check) {
					cout << n << "\n";
					break;
				}
				n++;
				check = 0;
			}
		}
	}
	return 0;
}