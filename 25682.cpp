#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, B[2010][2010], W[2010][2010], answer = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			W[i][j] = W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1];
			B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			if (c == 'W') {
				if ((i + j) % 2 == 0)
					B[i][j]++;
				else
					W[i][j]++;
			}
			else {
				if ((i + j) % 2 == 0)
					W[i][j]++;
				else
					B[i][j]++;
			}
		}
	}
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j <= M - K; j++) {
			answer = min(answer, B[i + K][j + K] - B[i][j + K] - B[i + K][j] + B[i][j]);
			answer = min(answer, W[i + K][j + K] - W[i][j + K] - W[i + K][j] + W[i][j]);
		}
	}
	cout << answer;
	return 0;
}