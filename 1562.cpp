#include <iostream>
using namespace std;
int N;
long long answer, dp[110][20][1 << 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (j == 0)
					dp[i][0][(1 << 0) | k] = (dp[i][0][(1 << 0) | k] + dp[i - 1][1][k]) % 1000000000;
				else if (j == 9)
					dp[i][9][(1 << 9) | k] = (dp[i][9][(1 << 9) | k] + dp[i - 1][8][k]) % 1000000000;
				else {
					dp[i][j][(1 << j) | k] = (dp[i][j][(1 << j) | k] + dp[i - 1][j - 1][k]) % 1000000000;
					dp[i][j][(1 << j) | k] = (dp[i][j][(1 << j) | k] + dp[i - 1][j + 1][k]) % 1000000000;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
		answer = (answer + dp[N][i][(1 << 10) - 1]) % 1000000000;
	cout << answer;
	return 0;
}