#include <iostream>
#include <algorithm>
using namespace std;
int n, M, C, P, dp[10010];
double m, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	while (!(!n && m == 0.00)) {
	    M = (m * 100) + 0.5;
		for (int i = 0; i <= M; i++)
			dp[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> C >> p;
			P = (p * 100) + 0.5;
			for (int j = P; j <= M; j++)
				dp[j] = max(dp[j], dp[j - P] + C);
		}
		cout << dp[M] << "\n";
		cin >> n >> m;
	}
	return 0;
}