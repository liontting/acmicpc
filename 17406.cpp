#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K, A[60][60], temp[60][60], R[10], C[10], S[10], check[10], answer = 100000;
vector<int> num;

void rotate(int r, int c, int s) {
	for (int i = 1; i <= s; i++) {
		int tmp = temp[r - i][c - i];
		for (int j = r - i + 1; j <= r + i; j++)
			temp[j - 1][c - i] = temp[j][c - i];
		for (int j = c - i + 1; j <= c + i; j++)
			temp[r + i][j - 1] = temp[r + i][j];
		for (int j = r + i - 1; j >= r - i; j--)
			temp[j + 1][c + i] = temp[j][c + i];
		for (int j = c + i - 1; j >= c - i + 1; j--)
			temp[r - i][j + 1] = temp[r - i][j];
		temp[r - i][c - i + 1] = tmp;
	}
}

void exe(int n) {
	if (n == K) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				temp[i][j] = A[i][j];
		for (int i = 0; i < K; i++)
			rotate(R[num[i]], C[num[i]], S[num[i]]);
		for (int i = 1; i <= N; i++) {
			int num = 0;
			for (int j = 1; j <= M; j++)
				num += temp[i][j];
			answer = min(answer, num);
		}
		return;
	}
	for (int i = 0; i < K; i++) {
		if (!check[i]) {
			check[i] = 1;
			num.push_back(i);
			exe(n + 1);
			num.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 0; i < K; i++)
		cin >> R[i] >> C[i] >> S[i];
	exe(0);
	cout << answer;
	return 0;
}