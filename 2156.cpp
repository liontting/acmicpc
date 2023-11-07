#include <iostream>
#include <algorithm>
using namespace std;
int n, podoju[10010], DP[10010], maxnum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> podoju[i];
	DP[0] = podoju[0];
	DP[1] = podoju[0] + podoju[1];
	DP[2] = max({ podoju[0] + podoju[1], podoju[0] + podoju[2], podoju[1] + podoju[2] });
	for (int i = 3; i < n; i++)
		DP[i] = max({ DP[i - 1], DP[i - 3] + podoju[i - 1] + podoju[i], DP[i - 2] + podoju[i] });
	cout << DP[n - 1];
	return 0;
}