#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, indegree[100010];
vector <int> v[100010];

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
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!indegree[i])
			q.push(i);
	for (int i = 1; i <= N; i++) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < (int)v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next]--;
			if (!indegree[next])
				q.push(next);
		}
	}
	return 0;
}