#include <iostream>
#include <queue>
using namespace std;
int N, root[1010];
long long int answer;
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
	cin >> N;
	for (int i = 1; i <= N; i++)
		root[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int C;
			cin >> C;
			if (j > i)
				pq.push(make_pair(-C, make_pair(i, j)));
		}
	}
	while (!pq.empty()) {
		int c = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (find(a) != find(b)) {
			uni(a, b);
			answer += c;
		}
		pq.pop();
	}
	cout << answer;
	return 0;
}