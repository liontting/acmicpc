#include <iostream>
using namespace std;
int N, ring[110];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ring[i];
	for (int i = 1; i < N; i++) {
		int n = gcd(ring[0], ring[i]);
		cout << ring[0] / n << "/" << ring[i] / n << "\n";
	}
	return 0;
}