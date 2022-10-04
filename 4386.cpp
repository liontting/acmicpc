#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int n, root[110];
double answer;
pair<double, double> star[110];
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		star[i].first = x;
		star[i].second = y;
		for (int j = 0; j < i; j++) {
			double c;
			c = sqrt(pow((star[i].first - star[j].first), 2) + pow((star[i].second - star[j].second), 2));
			pq.push(make_pair(-c, make_pair(i, j)));
		}
		root[i] = i;
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