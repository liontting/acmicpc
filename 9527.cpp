#include <iostream>
using namespace std;
long long A, B;

long long sum(long long n) {
	long long cnt = 0, a = n, b = 1;
	while (a) {
		cnt += (n + 1) / (b << 1) * b;
		if (a & 1) cnt += (n + 1) % b;
		a >>= 1;
		b <<= 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	cout << sum(B) - sum(A - 1);
	return 0;
}