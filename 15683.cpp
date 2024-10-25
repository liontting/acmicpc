#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M, office[10][10], answer = 2100000000;
vector<pair<int,int>> cctv;
pair<int,int> cctvn[6] = { {0,0},{4,1},{2,2},{4,2},{4,3},{1,4} };
int cctvx[6][15] = {
	{ 0 },
	{ -1,1,0,0 },
	{ -1,1,0,0 },
	{ -1,0,1,0,-1,0,1,0 },
	{ 1,0,0,-1,0,0,-1,1,0,-1,1,0 },
	{ -1,1,0,0 }
};
int cctvy[6][15] = {
	{ 0 },
	{ 0,0,-1,1 },
	{ 0,0,-1,1 },
	{ 0,1,0,1,0,-1,0,-1 },
	{ 0,-1,1,0,-1,1,0,0,1,0,0,-1 },
	{ 0,0,-1,1 }
};

void bt(int num, int check[10][10]) {
	if (num == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!check[i][j]) 
					cnt++;
		answer = min(answer, cnt);
		return;
	}
	int x = cctv[num].first, y = cctv[num].second;
	int n = office[x][y];

	check[x][y] = 1;
	for (int i = 0; i < cctvn[n].first; i++) {
		int idx = cctvn[n].second * i;
		queue<pair<int,int>> q;
		for (int j = idx; j < idx + cctvn[n].second; j++) {
			int nx = x + cctvx[n][j], ny = y + cctvy[n][j];
			while (nx >= 0 && nx < N && ny >= 0 && ny < M && check[nx][ny] != 2) {
				if (!check[nx][ny]) {
					check[nx][ny] = 1;
					q.push({nx,ny});
				}
				nx += cctvx[n][j], ny += cctvy[n][j];
			}
		}
		bt(num + 1, check);
		while (!q.empty()) {
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			check[nx][ny] = 0;
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int check[10][10] = { 0, };

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if (office[i][j] == 6)
				check[i][j] = 2;
			else if (office[i][j])
				cctv.push_back({ i,j });
		}
	}

	bt(0, check);

	cout << answer;
	return 0;
}
