#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int t, n, visited[110], check;
pair<int, int> home, store[110], festival;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		check = 0;
		for (int i = 0; i < 100; i++)
			visited[i] = 0;
		cin >> n;
		cin >> home.first >> home.second;
		for (int i = 0; i < n; i++)
			cin >> store[i].first >> store[i].second;
		cin >> festival.first >> festival.second;
		
		q.push(home);
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (abs(x - festival.first) + abs(y - festival.second) <= 1000) {
				check = 1;
				break;
			}
			for (int i = 0; i < n; i++) {
				if (!visited[i] && (abs(x - store[i].first) + abs(y - store[i].second) <= 1000)) {
					q.push(store[i]);
					visited[i] = 1;
				}
			}
		}
		if (check)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}