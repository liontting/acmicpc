#include <iostream>
#include <queue>
#include <string>
using namespace std;
int T, h, w, visited[110][110], key[30];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char building[110][110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		queue<pair<int, int>> q;
		int num = 0;
		for (int i = 0; i < 30; i++)
			key[i] = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				visited[i][j] = 0;
				if ((i == 0) || (i == (h - 1)) || (j == 0) || (j == (w - 1))) {
					if ((building[i][j] == '.') || (building[i][j] >= 'a' && building[i][j] <= 'z') || (building[i][j] == '$')) {
						q.push(make_pair(i, j));
						visited[i][j] = 1;
					}
					if (building[i][j] >= 'a' && building[i][j] <= 'z')
						key[building[i][j] - 'a'] = 1;
					if (building[i][j] == '$')
						num++;
				}
			}
		}
		string s;
		cin >> s;
		if (s[0] != '0')
			for (int i = 0; i < (int)s.size(); i++)
				key[s[i] - 'a'] = 1;
		while (1) {
			while (!q.empty()) {
				for (int i = 0; i < 4; i++) {
					int x = q.front().first + dx[i];
					int y = q.front().second + dy[i];
					if ((x >= 0) && (x < h) && (y >= 0) && (y < w) && !visited[x][y]) {
						if ((building[x][y] == '.') || (building[x][y] >= 'a' && building[x][y] <= 'z') || (building[x][y] == '$')) {
							q.push(make_pair(x, y));
							visited[x][y] = 1;
						}
						if (building[x][y] >= 'a' && building[x][y] <= 'z')
							key[building[x][y] - 'a'] = 1;
						if (building[x][y] == '$')
							num++;
					}
				}
				q.pop();
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if ((i == 0) || (i == (h - 1)) || (j == 0) || (j == (w - 1))) {
						if (!visited[i][j] && (building[i][j] >= 'A' && building[i][j] <= 'Z')) {
							if (key[building[i][j] - 'A']) {
								q.push(make_pair(i, j));
								visited[i][j] = 1;
							}
						}
					}
					if (visited[i][j]) {
						for (int k = 0; k < 4; k++) {
							int x = i + dx[k];
							int y = j + dy[k];
							if (!visited[x][y] && (building[x][y] >= 'A' && building[x][y] <= 'Z')) {
								if (key[building[x][y] - 'A']) {
									q.push(make_pair(x, y));
									visited[x][y] = 1;
								}
							}
						}
					}
				}
			}
			if (q.empty())
				break;
		}
		cout << num << "\n";
	}
	return 0;
}