#include <iostream>
using namespace std;
int M, N, jido[510][510], DP[510][510];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int fun(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return DP[M - 1][N - 1] = 1;
	if (DP[x][y] != -1)
		return DP[x][y];
	DP[x][y] = 0;
	for (int i = 0; i < 4; i++)
		if (x + dx[i] >= 0 && x + dx[i] < M && y + dy[i] >= 0 && y + dy[i] < N)
			if (jido[x][y] > jido[x + dx[i]][y + dy[i]])
				DP[x][y] = DP[x][y] + fun(x + dx[i], y + dy[i]);
	return DP[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> jido[i][j];
			DP[i][j] = -1;
		}
	}
	fun(0, 0);
	cout << DP[0][0];
	return 0;
}