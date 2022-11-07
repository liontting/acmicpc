#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;
int N, arr[510], dp[510][510];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i] >> arr[i + 1];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j + i <= N; j++) {
			dp[j][j + i] = INF;
			for (int k = j; k <= j + i; k++)
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + arr[j - 1] * arr[k] * arr[j + i]);
		}
	}
	cout << dp[1][N];
	return 0;
}