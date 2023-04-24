#include <iostream>
#include <algorithm>
using namespace std;
int x[5];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for (int i = 0; i < 3; i++)
		cin >> x[i];
	sort(x, x + 3);
	if (x[0] + x[1] > x[2])
		cout << x[0] + x[1] + x[2];
	else
		cout << 2 * (x[0] + x[1]) - 1;
	return 0;
}