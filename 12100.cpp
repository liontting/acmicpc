#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int N, board[25][25], answer;

void left(int n[25][25], int x);
void right(int n[25][25], int x);
void up(int n[25][25], int x);
void down(int n[25][25], int x);

void left(int n[25][25], int x) {
	int next[25][25];
	if (x == 5)
		return;
	for (int i = 0; i < N; i++) {
		queue<int> q1, q2;
		int zero = 0;
		for (int j = 0; j < N; j++) {
			if (n[i][j] != 0)
				q1.push(n[i][j]);
			else
				zero++;
		}
		while (!q1.empty()) {
			int tmp = q1.front();
			q1.pop();
			if (!q1.empty() && tmp == q1.front()) {
				answer = max(answer, 2 * tmp);
				q2.push(2 * tmp);
				q1.pop();
				zero++;
			}
			else
				q2.push(tmp);
		}
		for (int j = 0; j < zero; j++)
			q2.push(0);
		for (int j = 0; j < N; j++) {
			next[i][j] = q2.front();
			q2.pop();
		}
	}
	left(next, x + 1);
	right(next, x + 1);
	up(next, x + 1);
	down(next, x + 1);
}

void right(int n[25][25], int x) {
	int next[25][25];
	if (x == 5)
		return;
	for (int i = 0; i < N; i++) {
		queue<int> q1, q2;
		int zero = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (n[i][j] != 0)
				q1.push(n[i][j]);
			else
				zero++;
		}
		while (!q1.empty()) {
			int tmp = q1.front();
			q1.pop();
			if (!q1.empty() && tmp == q1.front()) {
				answer = max(answer, 2 * tmp);
				q2.push(2 * tmp);
				q1.pop();
				zero++;
			}
			else
				q2.push(tmp);
		}
		for (int j = 0; j < zero; j++)
			q2.push(0);
		for (int j = N - 1; j >= 0; j--) {
			next[i][j] = q2.front();
			q2.pop();
		}
	}
	left(next, x + 1);
	right(next, x + 1);
	up(next, x + 1);
	down(next, x + 1);
}

void up(int n[25][25], int x) {
	int next[25][25];
	if (x == 5)
		return;
	for (int i = 0; i < N; i++) {
		queue<int> q1, q2;
		int zero = 0;
		for (int j = 0; j < N; j++) {
			if (n[j][i] != 0)
				q1.push(n[j][i]);
			else
				zero++;
		}
		while (!q1.empty()) {
			int tmp = q1.front();
			q1.pop();
			if (!q1.empty() && tmp == q1.front()) {
				answer = max(answer, 2 * tmp);
				q2.push(2 * tmp);
				q1.pop();
				zero++;
			}
			else
				q2.push(tmp);
		}
		for (int j = 0; j < zero; j++)
			q2.push(0);
		for (int j = 0; j < N; j++) {
			next[j][i] = q2.front();
			q2.pop();
		}
	}
	left(next, x + 1);
	right(next, x + 1);
	up(next, x + 1);
	down(next, x + 1);
}

void down(int n[25][25], int x) {
	int next[25][25];
	if (x == 5)
		return;
	for (int i = 0; i < N; i++) {
		queue<int> q1, q2;
		int zero = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (n[j][i] != 0)
				q1.push(n[j][i]);
			else
				zero++;
		}
		while (!q1.empty()) {
			int tmp = q1.front();
			q1.pop();
			if (!q1.empty() && tmp == q1.front()) {
				answer = max(answer, 2 * tmp);
				q2.push(2 * tmp);
				q1.pop();
				zero++;
			}
			else
				q2.push(tmp);
		}
		for (int j = 0; j < zero; j++)
			q2.push(0);
		for (int j = N - 1; j >= 0; j--) {
			next[j][i] = q2.front();
			q2.pop();
		}
	}
	left(next, x + 1);
	right(next, x + 1);
	up(next, x + 1);
	down(next, x + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			answer = max(answer, board[i][j]);
		}
	}
	left(board, 0);
	right(board, 0);
	up(board, 0);
	down(board, 0);
	cout << answer;
	return 0;
}