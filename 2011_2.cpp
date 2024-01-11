#include <iostream>
#include <string>
using namespace std;
string password;
int dp[5010], N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> password;
	if (password[0] == '0') {
		cout << "0";
		return 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	N = (int)password.length();
	for (int i = 2; i <= N; i++) {
		if (password[i - 1] != '0')
			dp[i] = dp[i - 1] % 1000000;
		int num = (password[i - 2] - '0') * 10 + password[i - 1] - '0';
		if (num >= 10 && num <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	cout << dp[N];
	return 0;
}