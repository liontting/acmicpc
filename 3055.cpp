#include <iostream>
#include <queue>
using namespace std;
int R, C, visited[60][60], time, check;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char forest[60][60];
queue<pair<int, int>> hedgedog, water;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> forest[i][j];
			if (forest[i][j] == 'S')
				hedgedog.push({ i,j });
			if (forest[i][j] == '*')
				water.push({ i,j });
		}
	}
	while (!check) {
		time++;
		int s1 = hedgedog.size(), s2 = water.size();
		if (!s1)
			break;
		for (int i = 0; i < s2; i++) {
			int qx = water.front().first, qy = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int x = qx + dx[j], y = qy + dy[j];
				if (x >= 0 && x < R && y >= 0 && y < C) {
					if (forest[x][y] == '.') {
						forest[x][y] = '*';
						water.push({ x,y });
					}
				}
			}
		}
		for (int i = 0; i < s1; i++) {
			int qx = hedgedog.front().first, qy = hedgedog.front().second;
			hedgedog.pop();
			for (int j = 0; j < 4; j++) {
				int x = qx + dx[j], y = qy + dy[j];
				if (x >= 0 && x < R && y >= 0 && y < C) {
					if (!visited[x][y] && forest[x][y] == '.') {
						hedgedog.push({ x,y });
						visited[x][y] = 1;
					}
					if (forest[x][y] == 'D') {
						check = 1;
						break;
					}
				}
			}
			if (check)
				break;
		}
	}
	if (!check)
		cout << "KAKTUS";
	else
		cout << time;
	return 0;
}