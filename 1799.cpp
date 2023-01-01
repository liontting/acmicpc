#include <iostream>
using namespace std;
int n, board[20][20], visited1[30], visited2[30], bishop[2];

void dfs(int color, int x, int y, int cnt) {
	if (x >= n) {
		if (cnt > bishop[color])
			bishop[color] = cnt;
		return;
	}
	if (y >= n) {
		if (y % 2 == 0)
			dfs(color, x + 1, 1, cnt);
		else
			dfs(color, x + 1, 0, cnt);
		return;
	}
	if (board[x][y] && !visited1[x - y + n] && !visited2[x + y]) {
		visited1[x - y + n] = 1;
		visited2[x + y] = 1;
		dfs(color, x, y + 2, cnt + 1);
		visited1[x - y + n] = 0;
		visited2[x + y] = 0;
	}
	dfs(color, x, y + 2, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	dfs(0, 0, 0, 0);
	dfs(1, 0, 1, 0);
	cout << bishop[0] + bishop[1];
	return 0;
}