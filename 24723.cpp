#include <iostream>
using namespace std;
int N, answer = 1;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		answer *= 2;
	cout << answer;
	return 0;
}