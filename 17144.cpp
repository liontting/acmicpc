#include <iostream>
using namespace std;
int R, C, T, A[60][60], answer;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
pair<int, int> air_cleaner;

void spread() {
	int AA[60][60] = { 0 };
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (A[i][j] != 0 && A[i][j] != -1) {
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] >= 1 && i + dx[k] <= R && j + dy[k] >= 1 && j + dy[k] <= C) {
						if (A[i + dx[k]][j + dy[k]] != -1) {
							AA[i + dx[k]][j + dy[k]] += A[i][j] / 5;
							AA[i][j] -= A[i][j] / 5;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (A[i][j] != -1)
				A[i][j] += AA[i][j];
}

void clean_up(int x, int y) {
	for (int i = x - 1; i > 1; i--)
		A[i][1] = A[i - 1][1];
	for (int i = 1; i < C; i++)
		A[1][i] = A[1][i + 1];
	for (int i = 1; i < x; i++)
		A[i][C] = A[i + 1][C];
	for (int i = C; i > y; i--)
		A[x][i] = A[x][i - 1];
	A[x][y + 1] = 0;
}

void clean_down(int x, int y) {
	for (int i = x + 1; i < R; i++)
		A[i][1] = A[i + 1][1];
	for (int i = 1; i < C; i++)
		A[R][i] = A[R][i + 1];
	for (int i = R; i > x; i--)
		A[i][C] = A[i - 1][C];
	for (int i = C; i > y; i--)
		A[x][i] = A[x][i - 1];
	A[x][y + 1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1)
				air_cleaner = make_pair(i, j);
		}
	}
	for (int i = 0; i < T; i++) {
		spread();
		clean_up(air_cleaner.first - 1, air_cleaner.second);
		clean_down(air_cleaner.first, air_cleaner.second);
	}
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (A[i][j] > 0)
			answer += A[i][j];
	cout << answer;
	return 0;
}