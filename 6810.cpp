#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, sum = 9 * 1 + 7 * 3 + 8 * 1 + 0 * 3 + 9 * 1 + 2 * 3 + 1 * 1 + 4 * 3 + 1 * 1 + 8 * 3;
	cin >> n;
	sum += n * 1;
	cin >> n;
	sum += n * 3;
	cin >> n;
	sum += n * 1;
	cout << "The 1-3-sum is " << sum;
	return 0;
}