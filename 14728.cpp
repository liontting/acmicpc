#include <iostream>
#include <algorithm>
using namespace std;
int N, T, K[110], S[110], DP[2][10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		cin >> K[i] >> S[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T; j++) {
			if (j >= K[i])
				DP[i % 2][j] = max(DP[(i - 1) % 2][j], DP[(i - 1) % 2][j - K[i]] + S[i]);
			else
				DP[i % 2][j] = DP[(i - 1) % 2][j];
		}
	}
	cout << DP[N % 2][T];
	return 0;
}