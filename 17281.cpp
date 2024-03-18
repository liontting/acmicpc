#include <iostream>
#include <math.h>
using namespace std;
int N, result[55][10], order[10], visited[10], base[5], answer;

void check() {
	int score = 0, now = 1;
	for (int i = 0; i < N; i++) {
		int out = 0;
		for (int j = 1; j < 4; j++)
			base[j] = 0;
		while (out < 3) {
			int state = result[i][order[now++]];
			if (now > 9)
				now = 1;
			if (!state) {
				out++;
				continue;
			}
			base[0] = 1;
			for (int j = 3; j >= 0; j--) {
				if (base[j]) {
					base[j] = 0;
					if (j + state > 3)
						score++;
					else
						base[j + state] = 1;
				}
			}
		}
	}
	answer = max(answer, score);
}

void solve(int n) {
	if (n == 10) {
		check();
		return;
	}
	if (n == 4) {
		solve(n + 1);
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			order[n] = i;
			solve(n + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> result[i][j];
	order[4] = 1;
	solve(1);
	cout << answer;
	return 0;
}