#include <iostream>
#include <queue>
using namespace std;
int t, l, board[310][310], visited[310][310], sx, sy, ex, ey;
int dx[8] = { 1,-1,1,-1,2,-2,2,-2 }, dy[8] = { -2,2,2,-2,1,-1,-1,1 };
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		int num = 0;
		cin >> l;
		cin >> sx >> sy;
		q.push(make_pair(sx, sy));
		visited[sx][sy] = 1;
		cin >> ex >> ey;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == ex && y == ey) {
				cout << board[x][y] << "\n";
				for (int i = 0; i < l; i++) {
					for (int j = 0; j < l; j++) {
						board[i][j] = 0;
						visited[i][j] = 0;
					}
				}
				while (!q.empty())
					q.pop();
				break;
			}
			for (int i = 0; i < 8; i++) {
				if (x + dx[i] >= 0 && x + dx[i] < l && y + dy[i] >= 0 && y + dy[i] < l) {
					if (!visited[x + dx[i]][y + dy[i]]) {
						board[x + dx[i]][y + dy[i]] = board[x][y] + 1;
						q.push(make_pair(x + dx[i], y + dy[i]));
						visited[x + dx[i]][y + dy[i]] = 1;
					}
				}
			}
		}
	}
	return 0;
}