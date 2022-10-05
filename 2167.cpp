#include <iostream>
using namespace std;
int N, M, K, arr[310][310];
long long int sum[310][310];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		long long int hap = 0;
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			hap += arr[i][j];
			sum[i][j] = hap;
		}
	}
	cin >> K;
	while (K--) {
		int i, j, x, y;
		long long int hap = 0;
		cin >> i >> j >> x >> y;
		for (int k = i; k <= x; k++)
			hap += (sum[k][y] - sum[k][j - 1]);
		cout << hap << "\n";
	}
	return 0;
}