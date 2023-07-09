#include <iostream>
using namespace std;
long long int ja1, mo1, ja2, mo2, ja, mo;

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
	cin >> ja1 >> mo1;
	cin >> ja2 >> mo2;
	ja = ja1 * mo2 / Euclidean(mo1, mo2) + ja2 * mo1 / Euclidean(mo1, mo2);
	mo = mo1 * mo2 / Euclidean(mo1, mo2);
	cout << ja / Euclidean(ja, mo) << " " << mo / Euclidean(ja, mo);
	return 0;
}