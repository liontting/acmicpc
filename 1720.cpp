#include <iostream>
using namespace std;
int N;
long long dp[35];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
	if (N % 2)
		cout << (dp[N] + dp[(N - 1) / 2]) / 2;
	else
		cout << (dp[N] + dp[N / 2] + 2 * dp[(N - 2) / 2]) / 2;
	return 0;
}