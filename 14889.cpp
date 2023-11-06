#include <iostream>
#include <algorithm>
using namespace std;
int N, S[25][25], minnum = 2100000000, sum1, sum2, check[25];

void jaegui(int n, int idx) {
	if (n == 0) {
		for (int i = 0; i < N; i++) {
			if (check[i]) {
				for (int j = i + 1; j < N; j++)
					if (check[j])
						sum1 += S[i][j];
			}
			else {
				for (int j = i + 1; j < N; j++)
					if (!check[j])
						sum2 += S[i][j];
			}
		}
		minnum = min(minnum, abs(sum1 - sum2));
		sum1 = 0;
		sum2 = 0;
		return;
	}
	for (int i = idx; i < N; i++) {
		check[i] = 1;
		jaegui(n - 1, i + 1);
		check[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
			if (i > j)
				S[j][i] += S[i][j];
		}
	}
	jaegui(N / 2, 0);
	cout << minnum;
	return 0;
}