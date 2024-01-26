#include <iostream>
using namespace std;
int N, game[110][110];
int dx[2] = { 0,1 }, dy[2] = { 1,0 };
long long int dp[110][110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> game[i][j];
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1)
				break;
			for (int k = 0; k < 2; k++) {
				int x = i + game[i][j] * dx[k], y = j + game[i][j] * dy[k];
				if (x >= 0 && x < N && y >= 0 && y < N)
					dp[x][y] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}