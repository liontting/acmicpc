#include <iostream>
#include <queue>
using namespace std;
int N, M, visited[610][610], answer;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char campus[610][610];
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int x = q.front().first + dx[i];
			int y = q.front().second + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < M) {
				if (!visited[x][y] && campus[x][y] != 'X') {
					if (campus[x][y] == 'P')
						answer++;
					q.push(make_pair(x, y));
					visited[x][y] = 1;
				}
			}
		}
		q.pop();
	}
	if (!answer)
		cout << "TT";
	else
		cout << answer;
	return 0;
}