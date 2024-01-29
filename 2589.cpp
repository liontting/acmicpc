#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int N, M, answer, visited[60][60];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
char treasure[60][60];

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = 0;
	q.push({ { x,y },0 });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first.first, y = q.front().first.second;
		int n = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
				if (!visited[xx][yy] && treasure[xx][yy] == 'L') {
					q.push({ {xx,yy},n + 1 });
					visited[xx][yy] = 1;
					answer = max(answer, n + 1);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> treasure[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (treasure[i][j] == 'L')
				bfs(i, j);
	cout << answer;
	return 0;
}