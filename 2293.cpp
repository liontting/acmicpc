#include <iostream>
#include <algorithm>
using namespace std;
int n, k, coin[110];
long long int DP[10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j == coin[i])
				DP[j]++;
			if (j - coin[i] <= 10000 && j - coin[i] > 0)
				DP[j] += DP[j - coin[i]];
		}
	}
	cout << DP[k];
	return 0;
}