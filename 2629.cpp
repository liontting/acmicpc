#include <iostream>
#include <math.h>
using namespace std;
int N, M, weight[33], marble[10], DP[40010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];
	DP[0] = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 15001; j++) {
			if (DP[j] != 0 && DP[j] < i) {
				if (!DP[j + weight[i]])
					DP[j + weight[i]] = i;
				if (!DP[abs(j - weight[i])])
					DP[abs(j - weight[i])] = i;
			}
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> marble[i];
	for (int i = 1; i <= M; i++) {
		if (DP[marble[i]])
			cout << "Y ";
		else
			cout << "N ";
	}
	return 0;
}