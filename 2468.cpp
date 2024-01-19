#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
int N, arr[110][110], visited[110][110], answer, maxnum, num;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
priority_queue<int> pq;

void dfs(int x, int y, int h) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
			if (!visited[xx][yy] && arr[xx][yy] > h) {
				visited[xx][yy] = 1;
				dfs(xx, yy, h);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			maxnum = max(arr[i][j], maxnum);
		}
	}
	for (int i = 0; i < maxnum; i++) {
		num = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				visited[j][k] = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && arr[j][k] > i) {
					num++;
					visited[j][k] = 1;
					dfs(j, k, i);
				}
			}
		}
		answer = max(answer, num);
	}
	cout << answer;
	return 0;
}