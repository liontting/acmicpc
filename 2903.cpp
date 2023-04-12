#include <iostream>
using namespace std;
int N, answer = 4, square = 1, byeon = 1;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		answer += 5 * square - 2 * byeon * (byeon - 1);
		square *= 4;
		byeon *= 2;
	}
	cout << answer;
	return 0;
}