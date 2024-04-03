#include <iostream>
using namespace std;
int M, N, board[710][710], sum[1500], hap = 1, idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int zero, one, two;
		cin >> zero >> one >> two;
		sum[zero]++;
		sum[zero + one]++;
	}
	for (int i = M - 1; i >= 0; i--) {
		hap += sum[idx++];
		board[i][0] = hap;
	}
	for (int i = 1; i < M; i++) {
		hap += sum[idx++];
		board[0][i] = hap;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j)
				cout << board[0][j] << " ";
			else
				cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}