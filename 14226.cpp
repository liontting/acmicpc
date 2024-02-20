#include <iostream>
#include <queue>
using namespace std;
int S, visited[1010][1010];
queue<pair<pair<int, int>, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
	q.push({ {1,0},0 });
	visited[1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first, clip = q.front().first.second, time = q.front().second;
		if (x == S) {
			cout << time;
			break;
		}
		q.pop();
		if (x < 1001 && !visited[x][x]) {
			q.push({ {x,x},time + 1 });
			visited[x][x] = 1;
		}
		if (x + clip < 1001 && !visited[x + clip][clip] && clip) {
			q.push({ {x + clip,clip},time + 1 });
			visited[x + clip][clip] = 1;
		}
		if (x - 1 < 1001 && !visited[x - 1][clip] && x >= 2) {
			q.push({ {x - 1,clip},time + 1 });
			visited[x - 1][clip] = 1;
		}
	}
	return 0;
}