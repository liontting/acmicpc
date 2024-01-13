#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N, seat[25][25], s, n, answer;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, score[5] = { 0,1,10,100,1000 };
vector<int> v[410];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < pow(N, 2); i++) {
		int check1[25][25], check2[25][25], max1 = 0, max2 = 0, num1 = 0;
		pair<int, int> idx1[410], idx2[410];
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				check1[j][k] = 0;
				check2[j][k] = 0;
			}
		}
		idx2[0] = { 30,30 };
		cin >> s;
		for (int j = 0; j < 4; j++) {
			cin >> n;
			v[s].push_back(n);
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!seat[j][k])
					continue;
				for (int l = 0; l < 4; l++) {
					if (seat[j][k] == v[s][l]) {
						for (int m = 0; m < 4; m++) {
							int x = j + dx[m], y = k + dy[m];
							if (x > 0 && x <= N && y > 0 && y <= N)
								check1[x][y]++;
						}
					}
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (seat[j][k])
					continue;
				if (max1 < check1[j][k]) {
					max1 = check1[j][k];
					num1 = 1;
					idx1[0] = { j,k };
				}
				else if (max1 == check1[j][k])
					idx1[num1++] = { j,k };
			}
		}
		if (num1 == 1)
			seat[idx1[0].first][idx1[0].second] = s;
		else {
			for (int j = 0; j < num1; j++) {
				for (int k = 0; k < 4; k++) {
					int x = idx1[j].first + dx[k], y = idx1[j].second + dy[k];
					if ((x > 0 && x <= N && y > 0 && y <= N) && !seat[x][y])
						check2[idx1[j].first][idx1[j].second]++;
				}
			}
			for (int j = 0; j < num1; j++) {
				int x = idx1[j].first, y = idx1[j].second;
				if (max2 < check2[x][y]) {
					max2 = check2[x][y];
					idx2[0] = { x,y };
				}
				if (max2 == check2[x][y]) {
					if (idx2[0].first > x)
						idx2[0] = { x,y };
					else if (idx2[0].first == x && idx2[0].second > y)
						idx2[0] = { x,y };
				}
			}
			seat[idx2[0].first][idx2[0].second] = s;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int check = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				for (int l = 0; l < 4; l++)
					if ((x > 0 && x <= N && y > 0 && y <= N) && v[seat[i][j]][l] == seat[x][y])
						check++;
			}
			answer += score[check];
		}
	}
	cout << answer;
	return 0;
}