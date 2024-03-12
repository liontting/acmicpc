#include <iostream>
using namespace std;
int N, dp[35];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (!(N % 2)) {
		dp[2] = 3;
		for (int i = 4; i <= N; i += 2) {
			dp[i] = 3 * dp[i - 2] + 2;
			for (int j = 4; j < i; j += 2)
				dp[i] += 2 * dp[i - j];
		}
	}
	cout << dp[N];
	return 0;
}