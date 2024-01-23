#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int N, M, D, grid[20][20], answer, visited[20][20], archer[5], check[20][20];
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };

int bfs(int x) {
	int num = 0;
	for (int j = 0; j < N; j++)
		for (int k = 0; k < M; k++)
			if (visited[j][k] != 1)
				visited[j][k] = 0;
	for (int i = 0; i < 3; i++) {
		priority_queue<pair<int, pair<int, int>>> pq;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				check[j][k] = 0;
		pq.push({ 0, { -archer[i],x } });
		while (!pq.empty()) {
			int qy = -pq.top().second.first, qx = pq.top().second.second;
			pq.pop();
			for (int j = 0; j < 4; j++) {
				int xx = qx + dx[j], yy = qy + dy[j], d = abs(xx - x) + abs(yy - archer[i]);
				if (xx >= 0 && xx < x && yy >= 0 && yy < M && d <= D) {
					if (visited[xx][yy]) {
						if (visited[xx][yy] == 1) {
							num++;
							visited[xx][yy]++;
						}
						while (!pq.empty())
							pq.pop();
						break;
					}
					else if (!check[xx][yy]) {
						check[xx][yy] = 1;
						pq.push({ -d, { -yy, xx } });
					}
				}
			}
		}
	}
	return num;
}

int ex(int f, int s, int t) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = grid[i][j];
	archer[0] = f, archer[1] = s, archer[2] = t;
	int num = 0;
	for (int i = 0; i < N; i++)
		num += bfs(N - i);
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			for (int k = j + 1; k < M; k++)
				answer = max(answer, ex(i, j, k));
	cout << answer;
	return 0;
}