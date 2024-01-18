#include <iostream>
#include <algorithm>
using namespace std;
int n, num[100010], dp[100010][2], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		dp[i][0] = dp[i][1] = num[i];
	}
	answer = dp[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + num[i]);
		dp[i][1] = max(max(dp[i][1], dp[i - 1][0]), dp[i - 1][1]+num[i]);
		answer = max(max(answer, dp[i][0]), dp[i][1]);
	}
	cout << answer;
	return 0;
}