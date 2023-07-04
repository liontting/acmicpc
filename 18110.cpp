#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, nan2do[300010], rnd, aver, sum;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nan2do[i];
	sort(nan2do, nan2do + n);
	rnd = (int)round((double)n * 15 / 100);
	for (int i = rnd; i < n - rnd; i++)
		sum += nan2do[i];
	if (!n)
		cout << "0";
	else {
		aver = (int)round((double)sum / (n - 2 * rnd));
		cout << aver;
	}
	return 0;
}