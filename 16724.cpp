#include <iostream>
#include <string>
using namespace std;
int N, M, mapp[1010][1010], visited[1010][1010], answer;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
string s;

void dfs(int x, int y) {
	visited[x][y] = 1;
	int nx = x + dx[mapp[x][y]], ny = y + dy[mapp[x][y]];
	if (visited[nx][ny] == 1)
		answer++;
	if (!visited[nx][ny])
		dfs(nx, ny);
	visited[x][y] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'D')
				mapp[i][j] = 1;
			else if (s[j] == 'L')
				mapp[i][j] = 2;
			else if (s[j] == 'R')
				mapp[i][j] = 3;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dfs(i, j);
	cout << answer;
	return 0;
}