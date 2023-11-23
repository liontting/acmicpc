#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
int N, M, cycle;
long long int dist[510];
vector <pair<int, int>> v[510];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
	}
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto iter = v[j].begin(); iter != v[j].end(); iter++) {
				if (dist[j] != INF && dist[iter->first] > dist[j] + iter->second) {
					dist[iter->first] = dist[j] + iter->second;
					if (i == N)
						cycle = 1;
				}
			}
		}
	}
	if (cycle)
		cout << "-1";
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] != INF)
				cout << dist[i] << "\n";
			else
				cout << "-1\n";
		}
	}
	return 0;
}