#include <iostream>
#include <queue>
using namespace std;
int L, R, C, visited[40][40][40];
int dx[6] = { -1,1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
char building[40][40][40];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> L >> R >> C;
	while (L && R && C) {
		queue<pair<pair<int, int>, pair<int, int>>> q;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S')
						q.push({ {i,j},{k,0} });
					visited[i][j][k] = 0;
				}
			}
		}
		int flag = 0, ans = 0;
		while (!q.empty() && !flag) {
			int x = q.front().first.first, y = q.front().first.second, z = q.front().second.first, t = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int xx = x + dx[i], yy = y + dy[i], zz = z + dz[i];
				if (xx >= 0 && xx < L && yy >= 0 && yy < R && zz >= 0 && zz < C) {
					if (!visited[xx][yy][zz] && building[xx][yy][zz] == '.') {
						visited[xx][yy][zz] = 1;
						q.push({ {xx,yy},{zz,t + 1} });
					}
					if (building[xx][yy][zz] == 'E') {
						flag = 1;
						ans = t + 1;
					}
				}
			}
		}
		if (flag)
			cout << "Escaped in " << ans << " minute(s).\n";
		else
			cout << "Trapped!\n";
		cin >> L >> R >> C;
	}
	return 0;
}