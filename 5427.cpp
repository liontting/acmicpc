#include <iostream>
#include <queue>
using namespace std;
int T, w, h, visited[1010][1010];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char building[1010][1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		queue <pair<int, int>> fire, sang;
		int t = 0, check = 0;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = 0;
				cin >> building[i][j];
				if (building[i][j] == '*')
					fire.push({i, j});
				if (building[i][j] == '@')
					sang.push({i, j});
			}
		}
		while (!check) {
			t++;
			int size = fire.size(), c = 0;
			for (int i = 0; i < size; i++) {
				int qx = fire.front().first, qy = fire.front().second;
				fire.pop();
				for (int j = 0; j < 4; j++) {
					int x = qx + dx[j], y = qy + dy[j];
					if (x >= 0 && x < h && y >= 0 && y < w) {
						if (building[x][y] == '.' || building[x][y] == '@') {
							building[x][y] = '*';
							fire.push({x, y});
						}
					}
				}
			}
			size = sang.size();
			for (int i = 0; i < size; i++) {
				int qx = sang.front().first, qy = sang.front().second;
				sang.pop();
				if (qx == 0 || qx == h - 1 || qy == 0 || qy == w - 1) {
					check = 1;
					break;
				}
				for (int j = 0; j < 4; j++) {
					int x = qx + dx[j], y = qy + dy[j];
					if (x >= 0 && x < h && y >= 0 && y < w) {
						if (!visited[x][y] && building[x][y] == '.') {
							c = 1;
							sang.push({x, y});
							visited[x][y] = 1;
						}
					}
				}
			}
			if (!c)
				break;
		}
		if (check)
			cout << t << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}