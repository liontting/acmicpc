#include <iostream>
#include <algorithm>
using namespace std;
int N, cnt[6][3], dp[6][3], r, g, b, answer = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> r >> g >> b;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = 123456789;
	dp[0][0] = dp[1][0] = r;
	dp[2][1] = dp[3][1] = g;
	dp[4][2] = dp[5][2] = b;
	int n = N - 1;
	while (n--) {
		cin >> r >> g >> b;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				cnt[i][j] = dp[i][j];
		for (int i = 0; i < 6; i++) {
			dp[i][0] = r + min(cnt[i][1], cnt[i][2]);
			dp[i][1] = g + min(cnt[i][0], cnt[i][2]);
			dp[i][2] = b + min(cnt[i][0], cnt[i][1]);
		}
	}
	for (int i = 0; i < 3; i++) {
		if (i == 1 || i == 2) {
			answer = min(answer, dp[0][i]);
			answer = min(answer, dp[1][i]);
		}
		if (i == 0 || i == 2) {
			answer = min(answer, dp[2][i]);
			answer = min(answer, dp[3][i]);
		}
		if (i == 0 || i == 1) {
			answer = min(answer, dp[4][i]);
			answer = min(answer, dp[5][i]);
		}
	}
	cout << answer;
	return 0;
}