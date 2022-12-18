#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int N, M, board[1010][1010], visited[1010][1010], num, idx;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
vector<int> v;

void dfs(int x, int y) {
	num++;
	visited[x][y] = idx;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M) {
			if (!visited[x + dx[i]][y + dy[i]] && !board[x + dx[i]][y + dy[i]])
				dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			board[i][j] = s[j] - '0';
	}
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j] && !visited[i][j]) {
				num = 0;
				idx++;
				dfs(i, j);
				v.push_back(num);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++)
					if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < M)
						if (visited[i + dx[k]][j + dy[k]])
							s.insert(visited[i + dx[k]][j + dy[k]]);
				for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
					board[i][j] += v[*iter];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << board[i][j] % 10;
		cout << "\n";
	}
	return 0;
}