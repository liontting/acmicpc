#include <iostream>
#include <vector>
using namespace std;
int N, M, check, sign, visited[5][5];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char board[5][5];
vector<pair<int,int>> v;

void solve(int x, int y, int n, int ans) {
	if (n == 2 * M - 1) {
		if (!check && ans == N) {
			check = 1;
			cout << "1\n";
			for (int i = 0; i < 2 * M - 1; i++)
				cout << v[i].first << " " << v[i].second << "\n";
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int sx = x + dx[i], sy = y + dy[i];
		if (sx >= 0 && sx < 3 && sy >= 0 && sy < 3 && !visited[sx][sy]) {
			if (!((sx + sy) % 2)) {
				v.push_back({ sx,sy }); 
				visited[sx][sy] = 1;
				if (board[v[n - 1].first][v[n - 1].second] == '+')
					sign = 1;
				else
					sign = -1;
				solve(sx, sy, n + 1, ans + sign * (board[sx][sy] - '0'));
				visited[sx][sy] = 0;
				v.pop_back();
			}
			else {
				v.push_back({ sx,sy }); 
				visited[sx][sy] = 1;
				solve(sx, sy, n + 1, ans);
				visited[sx][sy] = 0;
				v.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!((i + j) % 2) && !check) {
				v.push_back({ i,j });
				visited[i][j] = 1;
				solve(i, j, 1, board[i][j] - '0');
				visited[i][j] = 0;
				v.pop_back();
			}
		}
	}
	if (!check)
		cout << "0\n";
	return 0;
}