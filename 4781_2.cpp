#include <iostream>
#include <algorithm>
using namespace std;
int n, M, C[5010], P[5010], dp[10010];
double m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	while (!(!n && m == 0.00)) {
	    M = (m * 100) + 0.5;
		for (int i = 0; i <= M; i++)
			dp[i] = 0;
		for (int i = 1; i <= n; i++) {
			double p;
			cin >> C[i] >> p;
			P[i] = (p * 100) + 0.5;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= M; j++) {
				if (j >= P[i])
					dp[j] = max(dp[j], dp[j - P[i]] + C[i]);
				else
					dp[j] = dp[j];
			}
		}
		cout << dp[M] << "\n";
		cin >> n >> m;
	}
	return 0;
}