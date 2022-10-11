#include <iostream>
using namespace std;
int board[10][10], finish;
char temp[10];

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << "\n";
	}
	finish = 1;
}

int check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (i != y && board[x][i] == num)
			return 0;
		if (i != x && board[i][y] == num)
			return 0;
	}
	int startx = (x / 3) * 3;
	int starty = (y / 3) * 3;
	for (int i = startx; i < startx + 3; i++)
		for (int j = starty; j < starty + 3; j++)
			if (i != x && j != y && board[i][j] == num)
				return 0;
	return 1;
}

void bfs(int x, int y) {
	if (finish)
		return;
	if (x == 9 && !finish) {
		print();
		return;
	}
	if (board[x][y]) {
		if (y == 8)
			bfs(x + 1, 0);
		else
			bfs(x, y + 1);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (check(x, y, i)) {
			board[x][y] = i;
			if (y == 8)
				bfs(x + 1, 0);
			else
				bfs(x, y + 1);
			board[x][y] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> temp;
		for (int j = 0; j < 9; j++)
			board[i][j] = temp[j] - '0';
	}
	bfs(0, 0);
	return 0;
}