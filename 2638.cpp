#include <iostream>
using namespace std;
int N, M, cheese[110][110], air[110][110], hour, finish;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void init_air() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			air[i][j] = cheese[i][j];
}

void dfs(int x, int y) {
	if (air[x][y])
		return;
	else {
		air[x][y] = -1;
		for (int k = 0; k < 4; k++)
			if (x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < M)
				dfs(x + dx[k], y + dy[k]);
	}
}

void one_hour() {
	int melt[110][110] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num = 0;
			if (air[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < M)
						if (air[i + dx[k]][j + dy[k]] == -1)
							num++;
				}
			}
			if (num >= 2)
				melt[i][j] = 1;
		}
	}
	int check = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cheese[i][j] -= melt[i][j];
			if (cheese[i][j] == 1)
				check = 1;
		}
	}
	if (!check)
		finish = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> cheese[i][j];
	while (!finish) {
		hour++;
		init_air();
		dfs(0, 0);
		one_hour();
	}
	cout << hour;
	return 0;
}