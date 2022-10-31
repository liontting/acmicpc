#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int idx, dp[100010][5][5], answer = INF;

int choose(int foot, int n) {
	if (foot == n)
		return 1;
	if (foot == 0)
		return 2;
	foot--, n--;
	if ((foot + 1) % 4 == n || (foot + 3) % 4 == n)
		return 3;
	if ((foot + 2) % 4 == n)
		return 4;
	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 1;
	for (int i = 0; i < 100005; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	while (N) {
		idx++;
		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[idx - 1][i][j] >= INF)
					continue;
				int a = choose(i, N);
				int b = choose(j, N);
				dp[idx][N][j] = min(dp[idx][N][j], dp[idx - 1][i][j] + a);
				dp[idx][i][N] = min(dp[idx][i][N], dp[idx - 1][i][j] + b);
			}
		}
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			answer = min(answer, dp[idx - 1][i][j]);
	cout << answer;
	return 0;
}