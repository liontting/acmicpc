#include <iostream>
#include <queue>
using namespace std;
int N, M, root[1010], sex[1010], answer;
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char c;
		cin >> c;
		if (c == 'M')
			sex[i] = 1;
		root[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if (sex[u] != sex[v])
			pq.push(make_pair(-d, make_pair(u, v)));
	}
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		if (find(u) != find(v)) {
			uni(u, v);
			answer += d;
		}
		pq.pop();
	}
	int check = 0;
	for (int i = 2; i <= N; i++)
		if (find(i) != find(1))
			check = 1;
	if (check)
		cout << "-1";
	else
		cout << answer;
	return 0;
}