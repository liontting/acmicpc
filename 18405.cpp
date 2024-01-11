#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int N, K, glass[210][210], S, X, Y;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
deque<pair<pair<int, int>, int>> dq;

bool cmp(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2) {
	int n1 = glass[e1.first.first][e1.first.second];
	int n2 = glass[e2.first.first][e2.first.second];
	return n1 < n2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> glass[i][j];
			if (glass[i][j])
				dq.push_back({ {i, j}, 0 });
		}
	}
	sort(dq.begin(), dq.end(), cmp);
	cin >> S >> X >> Y;
	while (!dq.empty()) {
		int x = dq.front().first.first;
		int y = dq.front().first.second;
		int t = dq.front().second;
		int n = glass[x][y];
		if (t == S)
			break;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
				if (!glass[nx][ny]) {
					glass[nx][ny] = n;
					dq.push_back({ {nx, ny}, t + 1 });
				}
			}
		}
	}
	cout << glass[X][Y];
	return 0;
}