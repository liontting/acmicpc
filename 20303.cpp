#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, c[30010], root[30010], DP[2][3010];
pair<int, int> satang[30010];
vector<pair<int, int>> v;

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void uni(int x, int y) {
	if (find(x) > find(y))
		root[find(x)] = find(y);
	else
		root[find(y)] = find(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		root[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	for (int i = 1; i <= N; i++) {
		satang[find(i)].first++;
		satang[find(i)].second += c[i];
	}
	for (int i = 1; i <= N; i++)
		if (satang[i].first != 0)
			v.push_back(satang[i]);
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 1; j < K; j++) {
			if (j >= v[i].first)
				DP[i % 2][j] = max(DP[(i - 1) % 2][j], DP[(i - 1) % 2][j - v[i].first] + v[i].second);
			else
				DP[i % 2][j] = DP[(i - 1) % 2][j];
		}
	}
	cout << DP[((int)v.size() - 1) % 2][K - 1];
	return 0;
}