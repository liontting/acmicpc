#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, R, visited[100010], now = 1;
vector<int> e[100010];
queue<int> q;

int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(e[i].begin(), e[i].end());
	q.push(R);
	visited[R] = now++;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (auto iter = e[n].begin(); iter < e[n].end(); iter++) {
			if (!visited[*iter]) {
				q.push(*iter);
				visited[*iter] = now++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
		cout << visited[i] << "\n";
	return 0;
}