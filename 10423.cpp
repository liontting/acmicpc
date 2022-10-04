#include <iostream>
#include <queue>
using namespace std;
int N, M, K, root[1010], answer;
priority_queue<pair<int, pair<int, int>>> pq;

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void uni(int x, int y) {
	if (find(x) != find(y))
		root[find(x)] = find(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		root[i] = i;
	for (int i = 0; i < K; i++) {
		int city;
		cin >> city;
		root[city] = 0;
	}
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push(make_pair(-w, make_pair(u, v)));
	}
	while (!pq.empty()) {
		int w = -pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		if (find(u) != find(v)) {
			uni(u, v);
			answer += w;
		}
		pq.pop();
	}
	cout << answer;
	return 0;
}