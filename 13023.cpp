#include <iostream>
#include <vector>
using namespace std;
int N, M, answer, visited[2010];
vector<int> v[2010];

void dfs(int x, int num) {
	if (num == 4) {
		answer++;
		return;
	}
	for (auto iter = v[x].begin(); iter != v[x].end(); iter++) {
		if (!visited[*iter]) {
			visited[*iter] = 1;
			dfs(*iter, num + 1);
			if (answer)
				return;
			visited[*iter] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		dfs(i, 0);
		if (answer)
			break;
		visited[i] = 0;
	}
	if (answer)
		cout << "1";
	else
		cout << "0";
	return 0;
}