#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T, N, K, W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int D[1010], indegree[1010] = { 0, }, answer[1010];
		vector<int> v[1010];
		queue<int> q;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> D[i];
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			v[X].push_back(Y);
			indegree[Y]++;
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0)
				q.push(i);
			answer[i] = D[i];
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < (int)v[cur].size(); i++) {
				int next = v[cur][i];
				indegree[next]--;
				answer[next] = max(answer[next], answer[cur] + D[next]);
				if (indegree[next] == 0)
					q.push(next);
			}
		}
		cout << answer[W] << "\n";
	}
	return 0;
}