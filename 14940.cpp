#include <iostream>
#include <queue>
using namespace std;
int n, m, map[1010][1010], dfs[1010][1010], visited[1010][1010];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
pair<int, int> start;
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				dfs[i][j] = 0;
			if (map[i][j] == 1)
				dfs[i][j] = -1;
			if (map[i][j] == 2) {
				start.first = i;
				start.second = j;
				q.push(start);
				visited[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int x = q.front().first + dx[i];
			int y = q.front().second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (map[x][y] == 1 && !visited[x][y]) {
					dfs[x][y] = dfs[q.front().first][q.front().second] + 1;
					visited[x][y] = 1;
					q.push(make_pair(x, y));
				}
			}
		}
		q.pop();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << dfs[i][j] << " ";
		cout << "\n";
	}
	return 0;
}