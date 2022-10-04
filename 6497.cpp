#include <iostream>
#include <queue>
using namespace std;
int m, n, root[200010];
long long int answer;
priority_queue<pair<long long int, pair<int, int>>> pq;

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
	cin >> m >> n;
	while (!(m == 0 && n == 0)) {
		answer = 0;
		for (int i = 0; i < m; i++)
			root[i] = i;
		for (int i = 0; i < n; i++) {
			int x, y;
			long long int z;
			cin >> x >> y >> z;
			pq.push(make_pair(-z, make_pair(x, y)));
			answer += z;
		}
		while (!pq.empty()) {
			long long int z = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			if (find(x) != find(y)) {
				uni(x, y);
				answer -= z;
			}
			pq.pop();
		}
		cout << answer << "\n";
		cin >> m >> n;
	}
	return 0;
}