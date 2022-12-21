#include <iostream>
#include <algorithm>
using namespace std;
char s[2510];
int N, palin[2510][2510], dp[2510];

void palindrome() {
	for (int i = 0; i < N; i++)
		palin[i][i] = 1;
	for (int i = 1; i < N; i++)
		if (s[i - 1] == s[i])
			palin[i - 1][i] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 0; j + i < N; j++)
			if (s[j] == s[j + i] && palin[j + 1][j + i - 1] == 1)
				palin[j][j + i] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (N = 1; s[N]; N++);
	palindrome();
	for (int i = 0; i < N; i++) {
		dp[i] = 2100000000;
		for (int j = 0; j <= i; j++)
			if (palin[j][i] == 1)
				dp[i] = min(dp[i], dp[j - 1] + 1);
	}
	cout << dp[N - 1];
	return 0;
}