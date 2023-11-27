#include <iostream>
#include <queue>
using namespace std;
int R, C, N, block[1010][1010], visited[1010][1010];
int dx[15], dy[15];
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> block[i][j];
			if (i)
				visited[i][j] = -1;
			else if (block[0][j])
				q.push(make_pair(0, j));
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> dx[i] >> dy[i];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == R - 1) {
			cout << visited[x][y];
			return 0;
		}
		for (int i = 0; i < N; i++) {
			if (x + dx[i] > 0 && x + dx[i] < R && y + dy[i] >= 0 && y + dy[i] < C) {
				if (visited[x + dx[i]][y + dy[i]] == -1 && block[x + dx[i]][y + dy[i]]) {
					visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
		}
	}
	cout << "-1";
	return 0;
}