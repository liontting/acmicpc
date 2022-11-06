#include <iostream>
#include <algorithm>
using namespace std;
int C, N, cost[30], customer[30], DP[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C >> N;
	for (int i = 1; i <= N; i++)
		cin >> cost[i] >> customer[i];
	for (int i = 1; i <= N; i++) {
		for (int j = cost[i]; j <= 100000; j++) {
			DP[j] = max(DP[j], DP[j - cost[i]] + customer[i]);
		}
	}
	for (int i = 0; i <= 100000; i++) {
		if (DP[i] >= C) {
			cout << i;
			break;
		}
	}
	return 0;
}