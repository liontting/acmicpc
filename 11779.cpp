#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;
int n, m, city[2][1010], start, dest, order[1010];
vector <pair<int, int>> bus[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= n; i++)
		city[0][i] = INF;
	cin >> start >> dest;
	priority_queue <pair<int, int>> pq;
	city[0][start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();
		if (nowdist > city[0][now])
			continue;
		for (int i = 0; i < (int)bus[now].size(); i++) {
			pair<int, int> next = bus[now][i];
			if (city[0][next.first] > nowdist + next.second) {
				city[0][next.first] = nowdist + next.second;
				pq.push(make_pair(-city[0][next.first], next.first));
				city[1][next.first] = now;
			}
		}
	}
	cout << city[0][dest] << "\n";
	int i = dest, cnt = 1;
	order[0] = dest;
	while (i != start) {
		i = city[1][i];
		order[cnt] = i;
		cnt++;
	}
	cout << cnt << "\n";
	for (int i = cnt - 1; i >= 0; i--)
		cout << order[i] << " ";
	return 0;
}