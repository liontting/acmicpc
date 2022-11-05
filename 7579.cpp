#include <iostream>
#include <algorithm>
using namespace std;
int N, M, m[110], c[110], sum, DP[2][10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> m[i];
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= c[i])
				DP[i % 2][j] = max(DP[(i - 1) % 2][j], DP[(i - 1) % 2][j - c[i]] + m[i]);
			else
				DP[i % 2][j] = DP[(i - 1) % 2][j];
		}
	}
	for (int i = 0; i <= sum; i++) {
		if (DP[N % 2][i] >= M) {
			cout << i;
			break;
		}
	}
	return 0;
}