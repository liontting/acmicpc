#include <iostream>
using namespace std;
int board[10][10];

int check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (i != x && board[i][y] == num)
			return 0;
		if (i != y && board[x][i] == num)
			return 0;
	}
	for (int i = 3 * (x / 3); i < 3 * (x / 3) + 3; i++)
		for (int j = 3 * (y / 3); j < 3 * (y / 3) + 3; j++)
			if (!(i == x && j == y) && board[i][j] == num)
				return 0;
	return 1;
}

void solve(int x, int y) {
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}
	if (y == 9) {
		solve(x + 1, 0);
		return;
	}
	if (board[x][y] != 0) {
		solve(x, y + 1);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(x, y, i)) {
			board[x][y] = i;
			solve(x, y + 1);
			board[x][y] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	solve(0, 0);
	return 0;
}