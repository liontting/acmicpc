#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, root[100010], answer;
priority_queue<pair<int, pair<int, int>>> pq;
vector <int> cost;

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
	for (int i = 0; i < N; i++)
		root[i] = i;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push(make_pair(-C, make_pair(A, B)));
	}
	while (!pq.empty()) {
		int c = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (find(a) != find(b)) {
			uni(a, b);
			answer += c;
			cost.push_back(c);
		}
		pq.pop();
	}
	answer -= cost[N - 2];
	cout << answer;
	return 0;
}