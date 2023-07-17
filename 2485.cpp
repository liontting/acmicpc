#include <iostream>
using namespace std;
long long int N, garosoo[100010], gcd, sub, dap;

long long int Euclidean(long long int x, long long int y) {
	long long int r = x % y;
	if (r == 0)
		return y;
	return Euclidean(y, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> garosoo[i];
	gcd = Euclidean(garosoo[1] - garosoo[0], garosoo[2] - garosoo[1]);
	for (int i = 3; i < N; i++)
		gcd = Euclidean(gcd, garosoo[i] - garosoo[i - 1]);
	sub = garosoo[N - 1] - garosoo[0];
	dap = sub / gcd;
	cout << dap - N + 1;
	return 0;
}