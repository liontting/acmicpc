#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, mapp[10][10], realmapp[10][10], maxnum;
vector <pair<int, int>> wall;
vector <pair<int, int>> selected;
queue <pair<int, int>> q;

void count() {
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (realmapp[i][j] == 0)
				result++;
	maxnum = max(maxnum, result);
}

void bfs() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (realmapp[i][j] == 2)
				q.push(make_pair(i, j));
	
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (x - 1 >= 0 && realmapp[x - 1][y] == 0) {
			realmapp[x - 1][y] = 2;
			q.push(make_pair(x - 1, y));
		}
		if (x + 1 < N && realmapp[x + 1][y] == 0) {
			realmapp[x + 1][y] = 2;
			q.push(make_pair(x + 1, y));
		}
		if (y - 1 >= 0 && realmapp[x][y - 1] == 0) {
			realmapp[x][y - 1] = 2;
			q.push(make_pair(x, y - 1));
		}
		if (y + 1 < M && realmapp[x][y + 1] == 0) {
			realmapp[x][y + 1] = 2;
			q.push(make_pair(x, y + 1));
		}
	}
	count();
}

void select_wall(int n) {
	if (selected.size() == 3) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				realmapp[i][j] = mapp[i][j];
		for (int i = 0; i < 3; i++)
			realmapp[selected[i].first][selected[i].second] = 1;
		bfs();
		return;
	}

	for (int i = n; i < (int)wall.size(); i++) {
		selected.push_back(wall[i]);
		select_wall(i + 1);
		selected.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapp[i][j];
			if (!mapp[i][j])
				wall.push_back(make_pair(i, j));
		}
	}
	select_wall(0);
	cout << maxnum;
	return 0;
}