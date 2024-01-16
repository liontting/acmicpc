#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, x, y, answer;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	x = v[0].first, y = v[0].second;
	for (int i = 1; i < N; i++) {
		if (y >= v[i].first) {
			if (y < v[i].second)
				y = v[i].second;
		}
		else {
			answer += y - x;
			x = v[i].first, y = v[i].second;
		}
	}
	answer += y - x;
	cout << answer;
	return 0;
}