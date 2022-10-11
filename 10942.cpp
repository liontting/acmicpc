#include <iostream>
using namespace std;
int N, M, num[2010], dp[2010][2010];

int palindrome(int s, int e) {
	if (s > e)
		return 1;
	if (dp[s][e] != -1)
		return dp[s][e];
	if (num[s] != num[e])
		return dp[s][e] = 0;
	return dp[s + 1][e - 1] = palindrome(s + 1, e - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = -1;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << palindrome(S, E) << "\n";
	}
	return 0;
}