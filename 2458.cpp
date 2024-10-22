#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M, check[2][510], answer, cnt;
vector<int> edge[2][510];

void dive(int e, int n) {
	check[e][n] = 1;

	for (int i = 0; i < edge[e][n].size(); i++) {
		if (!check[e][edge[e][n][i]]) {
			cnt++;
			dive(e, edge[e][n][i]);
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edge[0][a].push_back(b);
		edge[1][b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(check, 0, sizeof(check));
		dive(0, i);
		dive(1, i);
		if (cnt == N - 1)
			answer++;
	}
	cout << answer;
	return 0;
}
