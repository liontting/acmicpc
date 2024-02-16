#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int visited[15][10], answer;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char puyo[15][10];
queue<pair<int, int>> visit;

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	int num = 1;
	visited[x][y] = 1;
	q.push({x, y});
	while (!q.empty()) {
		int qx = q.front().first, qy = q.front().second;
		visit.push({qx, qy});
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = qx + dx[i], yy = qy + dy[i];
			if (xx >= 0 && xx < 12 && yy >= 0 && yy < 6) {
				if (!visited[xx][yy] && puyo[qx][qy] == puyo[xx][yy]) {
					num++;
					visited[xx][yy] = 1;
					q.push({xx, yy});
				}
			}
		}
	}
	while (!visit.empty()) {
		int x = visit.front().first, y = visit.front().second;
		visit.pop();
		if (num >= 4)
			puyo[x][y] = '.';
	}
	return num;
}

void clean() {
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j > 0; j--) {
			if (puyo[j][i] != '.')
				continue;
			for (int k = 0; k < j; k++)
				if (puyo[k][i] != '.')
					swap(puyo[j][i], puyo[k][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> puyo[i][j];
	while (1) {
		int check = 0;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				visited[i][j] = 0;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (!visited[i][j] && puyo[i][j] != '.')
					if (bfs(i, j) >= 4)
						check = 1;
		if (!check)
			break;
		clean();
		answer++;
	}
	cout << answer;
	return 0;
}