#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, K, X, dist[300010];
vector <pair<int, int>> path[300010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		path[A].push_back(make_pair(B, 1));
	}
	for (int i = 1; i <= N; i++)
		dist[i] = 987654321;
	priority_queue<pair<int, int>> pq;
	dist[X] = 0;
	pq.push(make_pair(0, X));
	while (!pq.empty()) {
		int nowdist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (nowdist > dist[now])
			continue;
		for (int i = 0; i < (int)path[now].size(); i++) {
			pair<int, int> next = path[now][i];
			if (dist[next.first] > nowdist + next.second) {
				dist[next.first] = nowdist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
	int check = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << "\n";
			check = 1;
		}
	}
	if (!check)
		cout << "-1";
	return 0;
}