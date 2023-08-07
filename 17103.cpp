#include <iostream>
using namespace std;
int T, N, prime[1000001];

void eratosthenes() {
	for (int i = 2; i <= 1000000; i++)
		prime[i] = 1;
	for (int i = 2; i * i <= 1000000; i++)
		if (prime[i])
			for (int j = i * i; j <= 1000000; j += i)
				prime[j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	eratosthenes();
	for (int i = 0; i < T; i++) {
		int answer = 0;
		cin >> N;
		for (int j = 2; j <= N / 2; j++)
			if (prime[j] && prime[N - j])
				answer++;
		cout << answer << "\n";
	}
	return 0;
}