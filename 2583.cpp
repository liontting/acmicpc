#include <iostream>
#include <queue>
using namespace std;
int M, N, K, paper[110][110], answer, num;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
priority_queue<int> pq;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < M && yy >= 0 && yy < N) {
			if (!paper[xx][yy]) {
				paper[xx][yy] = 1;
				num++;
				dfs(xx, yy);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
			for (int k = x1; k < x2; k++)
				paper[j][k] = 1;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!paper[i][j]) {
				num = 1;
				answer++;
				paper[i][j] = 1;
				dfs(i, j);
				pq.push(-num);
			}
		}
	}
	cout << answer << "\n";
	while (!pq.empty()) {
		cout << -pq.top() << " ";
		pq.pop();
	}
	return 0;
}