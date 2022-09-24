#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;
int n, m, r, answer, maxnum;
vector <pair<int, int>> v[110];
int jiyeok[110], dis[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> jiyeok[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back(make_pair(b, l));
		v[b].push_back(make_pair(a, l));
	}
	int repeat = 1;
	while (repeat <= n) {
		for (int i = 1; i <= n; i++)
			dis[i] = INF;
		priority_queue <pair<int, int>> pq;
		dis[repeat] = 0;
		pq.push(make_pair(0, repeat));
		while (!pq.empty()) {
			int now = pq.top().second;
			int nowdist = -pq.top().first;
			pq.pop();
			for (int i = 0; i < (int)v[now].size(); i++) {
				pair<int, int> next = v[now][i];
				if (dis[next.first] >= nowdist + next.second) {
					dis[next.first] = nowdist + next.second;
					pq.push(make_pair(-dis[next.first], next.first));
				}
			}
		}
		answer = 0;
		for (int i = 1; i <= n; i++)
			if (dis[i] <= m)
				answer += jiyeok[i];
		if (maxnum < answer)
			maxnum = answer;
		repeat++;
	}
	cout << maxnum;
	return 0;
}