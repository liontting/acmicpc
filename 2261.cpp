#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#define INF 20000
using namespace std;
int n, mini, idx;
vector<pair<int, int>> v;
set<pair<int, int>> s;

int dist(pair<int, int> a, pair<int, int> b) {
	int x = (a.first - b.first) * (a.first - b.first);
	int y = (a.second - b.second) * (a.second - b.second);
	return x + y;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	s.insert(make_pair(v[0].second, v[0].first));
	s.insert(make_pair(v[1].second, v[1].first));
	int mini = dist(v[0], v[1]);
	for (int i = 2; i < n; i++) {
		while (idx < i) {
			int d = v[i].first - v[idx].first;
			if (d * d <= mini)
				break;
			else {
				s.erase(make_pair(v[idx].second, v[idx].first));
				idx++;
			}
		}
		auto start = s.lower_bound(make_pair((int)(v[i].second - sqrt(mini)), -INF));
		auto end = s.upper_bound(make_pair((int)(v[i].second + sqrt(mini)), INF));
		for (auto it = start; it != end; it++)
			mini = min(mini, dist(make_pair(it->second, it->first), v[i]));
		s.insert(make_pair(v[i].second, v[i].first));
	}
	cout << mini;
	return 0;
}