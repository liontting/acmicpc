#include <iostream>
#include <vector>
using namespace std;
int K, V, E, visited[20010], check;
vector<int> e[20010];

void dfs(int x, int c) {
	if (check)
		return;
	visited[x] = c;
	for (auto iter = e[x].begin(); iter != e[x].end(); iter++) {
		if (!visited[*iter])
			dfs(*iter, -c);
		else if (visited[x] == visited[*iter]) {
			check = 1;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	while (K--) {
		cin >> V >> E;
		check = 0;
		for (int i = 1; i <= V; i++) {
			visited[i] = 0;
			e[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (!visited[i])
				dfs(i, 1);
			if (check)
				break;
		}
		if (!check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}