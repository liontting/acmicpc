#include <iostream>
using namespace std;
int N, buf[10];

int check(int n) {
	if (n == 1)
		return 0;
	for (int i = 2; i * i <= n; i++)
		if (!(n % i))
			return 0;
	return 1;
}

void bt(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++)
			cout << buf[i];
		cout << "\n";
		return;
	}
	int num = 0, mul = 1;
	for (int i = 0; i < n; i++)
		mul *= 10;
	for (int i = 0; i < n; i++) {
		num += mul * buf[i];
		mul /= 10;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(num + i)) {
			buf[n] = i;
			bt(n + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	bt(0);
	return 0;
}