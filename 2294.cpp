#include <iostream>
#include <algorithm>
using namespace std;
int n, k, coin[110], dp[20010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	sort(coin, coin + n);
	for (int i = 1; i <= k; i++)
		dp[i] = 2 * k;
	for (int i = 0; i < n; i++)
		if (coin[i] <= k)
			for (int j = coin[i]; j <= k; j++)
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	if (dp[k] == 2 * k)
		cout << "-1";
	else
		cout << dp[k];
	return 0;
}