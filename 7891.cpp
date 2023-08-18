#include <iostream>
using namespace std;
int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}