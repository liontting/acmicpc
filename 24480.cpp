#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, R, visited[100010], num = 1;
vector<int> e[100010];

void dfs(int x) {
	for (auto iter = e[x].begin(); iter != e[x].end(); iter++) {
		if (!visited[*iter]) {
			visited[*iter] = num++;
			dfs(*iter);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(e[i].begin(), e[i].end(), greater<>());
	visited[R] = num++;
	dfs(R);
	for (int i = 1; i <= N; i++)
		cout << visited[i] << "\n";
	return 0;
}