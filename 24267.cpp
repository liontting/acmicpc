#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long long n, answer = 0;
	cin >> n;
	for (long long i = 1; i <= n - 2; i++)
		answer += i * (i + 1) / 2;
	cout << answer << "\n" << "3";
	return 0;
}