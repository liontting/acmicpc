#include <iostream>
using namespace std;
int N, dp[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	if (N % 2)
		cout << "0";
	else {
		N /= 2;
		dp[1] = 3;
		for (int i = 2; i <= N; i++) {
			dp[i] = 3 * dp[i - 1] + 2;
			for (int j = 2; j < i; j++)
				dp[i] += 2 * dp[i - j];
		}
		cout << dp[N];
	}
	return 0;
}