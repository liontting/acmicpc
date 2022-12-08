#include <iostream>
using namespace std;
int T;
long long A, B;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << A * B / gcd(A, B) << "\n";
	}
	return 0;
}