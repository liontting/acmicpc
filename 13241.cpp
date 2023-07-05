#include <iostream>
using namespace std;
long long int A, B;

long long int Euclidean(long long int x, long long int y) {
	long long int r = x % y;
	if (r == 0)
		return y;
	return Euclidean(y, r);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> A >> B;
	cout << A * B / Euclidean(A, B);
	return 0;
}