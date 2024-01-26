#include <iostream>
using namespace std;
int N, number[110];
long long int dp[110][30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];
	dp[0][number[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			int n1 = j + number[i], n2 = j - number[i];
			if (n1 >= 0 && n1 < 21)
				dp[i][n1] += dp[i - 1][j];
			if (n2 >= 0 && n2 < 21)
				dp[i][n2] += dp[i - 1][j];
		}
	}
	cout << dp[N - 2][number[N - 1]];
	return 0;
}