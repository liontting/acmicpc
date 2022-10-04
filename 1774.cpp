#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int N, M, root[1010];
long long int x[1010], y[1010];
double answer;
priority_queue<pair<double, pair<int, int>>> pq;

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
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; j++) {
			double c;
			c = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
			pq.push(make_pair(-c, make_pair(i, j)));
		}
		root[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		uni(find(a), find(b));
	}
	while (!pq.empty()) {
		double c = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (find(a) != find(b)) {
			uni(a, b);
			answer += c;
		}
		pq.pop();
	}
	cout << fixed;
	cout.precision(2);
	cout << answer;
	return 0;
}