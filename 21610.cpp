#include <iostream>
#include <queue>
using namespace std;
int N, M, A[60][60], visited[60][60], answer;
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 }, dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	q.push({ N - 1,0 });
	q.push({ N - 1,1 });
	q.push({ N - 2,0 });
	q.push({ N - 2,1 });
	for (int i = 0; i < M; i++) {
		int d, s, size = q.size();
		cin >> d >> s;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				visited[j][k] = 0;
		for (int j = 0; j < size; j++) {
			int x = q.front().first + s * dx[d], y = q.front().second + s * dy[d];
			q.pop();
			while (x < 0)
				x += N;
			while (y < 0)
				y += N;
			while (x >= N)
				x -= N;
			while (y >= N)
				y -= N;
			visited[x][y] = 1;
			A[x][y]++;
			q.push({ x,y });
		}
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second, n = 0;
			q.pop();
			for (int j = 2; j < 9; j += 2) {
				int xx = x + dx[j], yy = y + dy[j];
				if (xx >= 0 && xx < N && yy >= 0 && yy < N)
					if (A[xx][yy])
						n++;
			}
			A[x][y] += n;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (A[j][k] >= 2 && !visited[j][k]) {
					A[j][k] -= 2;
					q.push({ j,k });
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			answer += A[i][j];
	cout << answer;
	return 0;
}