#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, indegree[32010];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[32010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			pq.push(i);
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		answer.push_back(cur);
		for (int i = 0; i < (int)v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)
				pq.push(next);
		}
	}
	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	return 0;
}