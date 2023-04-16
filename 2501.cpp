#include <iostream>
using namespace std;
int N, K, num, answer;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			num++;
			if (num == K) {
				answer = i;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}