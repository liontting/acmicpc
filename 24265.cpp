#include <iostream>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	long long n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			answer++;
	cout << answer << "\n" << "2";
	return 0;
}