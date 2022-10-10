#include <iostream>
using namespace std;
int R, C, check[50], answer;
char alphabet[25][25];

void dfs(int x, int y) {
	check[alphabet[x][y] - 'A'] = 1;
	int temp = 0;
	for (int i = 0; i <= 'Z' - 'A'; i++)
		if (check[i])
			temp++;
	if (answer < temp)
		answer = temp;
	if (x - 1 >= 0) {
		if (!check[alphabet[x - 1][y] - 'A']) {
			dfs(x - 1, y);
			check[alphabet[x - 1][y] - 'A'] = 0;
		}
	}
	if (x + 1 < R) {
		if (!check[alphabet[x + 1][y] - 'A']) {
			dfs(x + 1, y);
			check[alphabet[x + 1][y] - 'A'] = 0;
		}
	}
	if (y - 1 >= 0) {
		if (!check[alphabet[x][y - 1] - 'A']) {
			dfs(x, y - 1);
			check[alphabet[x][y - 1] - 'A'] = 0;
		}
	}
	if (y + 1 < C) {
		if (!check[alphabet[x][y + 1] - 'A']) {
			dfs(x, y + 1);
			check[alphabet[x][y + 1] - 'A'] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> alphabet[i][j];
	dfs(0, 0);
	cout << answer;
	return 0;
}