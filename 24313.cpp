#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long long a1, a0, c, n0;
	cin >> a1 >> a0;
	cin >> c;
	cin >> n0;
	if (a1 > c)
		cout << "0";
	else if (a1*n0 + a0 > c*n0)
		cout << "0";
	else
		cout << "1";
	return 0;
}