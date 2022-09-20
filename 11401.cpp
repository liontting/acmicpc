#include <iostream>
using namespace std;
long long X = 1000000007, answer;
int N, K;

long long inverse(long long a, long long n) {
	long long r = 1;
	while (n) {
		if (n % 2)
			r = (r * a) % X;
		a = (a * a) % X;
		n /= 2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long A, B;
	cin >> N >> K;
	A = 1, B = 1;
	for (int i = 1; i <= K; i++)
		A = (A * i) % X;
	for (int i = N - K + 1; i <= N; i++)
		B = (B * i) % X;
	answer = (B * inverse(A, X - 2) % X) % X;
	cout << answer;
	return 0;
}