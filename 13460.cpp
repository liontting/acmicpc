#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int N, M, answer, visited[15][15][15][15];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
char board[15][15];
pair<int, int> red, blue;
queue < pair<pair<int, int>, pair<int, int>> > q;

int bfs() {
	while (!q.empty()) {
		if (answer >= 10)
			return -1;
		int q_len = q.size();
		answer++;
		while (q_len--) {
			int rx = q.front().first.first;
			int ry = q.front().first.second;
			int bx = q.front().second.first;
			int by = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int checkr = 0, checkb = 0;
				int drx = rx, dry = ry, dbx = bx, dby = by;
				while (board[drx + dx[i]][dry + dy[i]] != '#') {
					if (board[drx + dx[i]][dry + dy[i]] == 'O') {
						checkr = 1;
						break;
					}
					drx = drx + dx[i];
					dry = dry + dy[i];
				}
				while (board[dbx + dx[i]][dby + dy[i]] != '#') {
					if (board[dbx + dx[i]][dby + dy[i]] == 'O') {
						checkb = 1;
						break;
					}
					dbx = dbx + dx[i];
					dby = dby + dy[i];
				}
				if (checkr && !checkb)
					return answer;
				if (checkb)
					continue;
				if (drx == dbx && dry == dby) {
					if (abs(drx - rx) + abs(dry - ry) > abs(dbx - bx) + abs(dby - by)) {
						drx -= dx[i];
						dry -= dy[i];
					}
					else {
						dbx -= dx[i];
						dby -= dy[i];
					}
				}
				if (visited[drx][dry][dbx][dby])
					continue;
				q.push({ {drx,dry},{dbx,dby} });
				visited[drx][dry][dbx][dby] = 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R')
				red = make_pair(i, j);
			if (board[i][j] == 'B')
				blue = make_pair(i, j);
		}
	}
	q.push({{red.first, red.second}, {blue.first, blue.second}});
	visited[red.first][red.second][blue.first][blue.second] = 1;
	cout << bfs();
	return 0;
}