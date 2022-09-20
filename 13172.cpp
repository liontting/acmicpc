#include <iostream>
using namespace std;
int M;
long long X = 1000000007, N, S, answer;

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

long long modular(long long a, long long b) {
	return inverse(a, X - 2) * b % X;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N >> S;
		answer = (answer + modular(N, S) % X) % X;
	}
	cout << answer;
	return 0;
}