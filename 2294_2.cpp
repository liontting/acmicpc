#include <iostream>
#include <algorithm>
using namespace std;
int n, k, coin[110], dp[10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	for (int i = 1; i <= k; i++)
		dp[i] = 10001;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	if (dp[k] == 10001)
		cout << "-1";
	else
		cout << dp[k];
	return 0;
}