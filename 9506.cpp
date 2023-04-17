#include <iostream>
using namespace std;
int n, sum, num[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> n;
	while (n != -1) {
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				num[i] = 1;
			}
		}
		if (sum == n) {
			cout << n << " = 1";
			for (int i = 2; i < n; i++)
				if (num[i] == 1)
					cout << " + " << i;
			cout << "\n";
		}
		else
			cout << n << " is NOT perfect.\n";
		for (int i = 1; i < n; i++)
			num[i] = 0;
		sum = 0;
		cin >> n;
	}
	return 0;
}