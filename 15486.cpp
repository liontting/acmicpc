#include <iostream>
#include <algorithm>
using namespace std;
int N, T, P, dp[1500060];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		if (dp[i + 1] < dp[i])
			dp[i + 1] = dp[i];
		dp[i + T] = max(dp[i + T], dp[i] + P);
	}
	cout << dp[N];
	return 0;
}