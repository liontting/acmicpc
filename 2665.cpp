#include <iostream>
#include <queue>
#define INF 2100000000
using namespace std;
int n, room[60][60], dist[60][60];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char str[60][60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> str[i][j];
			room[i][j] = (str[i][j] == '1') ? 1 : 2500;
			dist[i][j] = INF;
		}
	}
	dist[0][0] = room[0][0];
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[0][0], { 0,0 } });
	while (!pq.empty()) {
		int nowx = pq.top().second.first, nowy = pq.top().second.second;
		int nowdist = -pq.top().first;
		pq.pop();
		if (nowdist > dist[nowx][nowy])
			continue;
		for (int i = 0; i < 4; i++) {
			int x = nowx + dx[i], y = nowy + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (dist[x][y] > nowdist + room[x][y]) {
					dist[x][y] = nowdist + room[x][y];
					pq.push({ -dist[x][y], {x,y} });
				}
			}
		}
	}
	cout << dist[n - 1][n - 1] / 2500;
	return 0;
}