#include <iostream>
#include <string>
using namespace std;
string password;
int dp[5010][2], N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> password;
	dp[0][0] = 1;
	if (password[0] == '0') {
		cout << "0";
		return 0;
	}
	N = (int)password.length();
	for (int i = 1; i < N; i++) {
		if (password[i] == '0') {
			if (password[i - 1] == '1' || password[i - 1] == '2')
				dp[i][1] = dp[i-1][0] % 1000000;
			else
				break;
		}
		else if (password[i - 1] == '1' || (password[i - 1] == '2' && (password[i] >= '1' && password[i] <= '6'))) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
			dp[i][1] = dp[i - 1][0] % 1000000;
		}
		else
			dp[i][0] = (dp[i-1][0] + dp[i - 1][1]) % 1000000;
	}
	cout << (dp[N - 1][0] + dp[N - 1][1]) % 1000000;
	return 0;
}