#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, root[100010];
long long int answer;
pair<int, int> X[100010];
pair<int, int> Y[100010];
pair<int, int> Z[100010];
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X[i] = make_pair(x, i);
		Y[i] = make_pair(y, i);
		Z[i] = make_pair(z, i);
		root[i] = i;
	}
	sort(X, X + n);
	sort(Y, Y + n);
	sort(Z, Z + n);
	for (int i = 0; i < n - 1; i++) {
		pq.push(make_pair(-abs(X[i + 1].first - X[i].first), make_pair(X[i + 1].second, X[i].second)));
		pq.push(make_pair(-abs(Y[i + 1].first - Y[i].first), make_pair(Y[i + 1].second, Y[i].second)));
		pq.push(make_pair(-abs(Z[i + 1].first - Z[i].first), make_pair(Z[i + 1].second, Z[i].second)));
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