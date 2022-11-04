#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, indegree[1010];
vector<int> v[1010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num, a, b;
		cin >> num;
		cin >> a;
		for (int j = 0; j < num - 1; j++) {
			cin >> b;
			v[a].push_back(b);
			indegree[b]++;
			a = b;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		for (int i = 0; i < (int)v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	if (answer.size() != N)
		cout << "0";
	else
		for (int i = 0; i < (int)answer.size(); i++)
			cout << answer[i] << "\n";
	return 0;
}