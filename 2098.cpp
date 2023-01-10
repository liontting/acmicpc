#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int N, W[20][20], dp[20][1 << 16];

int dfs(int cur, int visited) {
	if (visited == (1 << N) - 1)
		return W[cur][0] ? W[cur][0] : 987654321;
	if (dp[cur][visited] != -1)
		return dp[cur][visited];
	dp[cur][visited] = 987654321;
	for (int i = 0; i < N; i++) {
		if ((visited & (1 << i)) || (!W[cur][i]))
			continue;
		dp[cur][visited] = min(dp[cur][visited], dfs(i, visited | (1 << i)) + W[cur][i]);
	}
	return dp[cur][visited];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1 << 0);
	return 0;
}