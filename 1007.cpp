#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int T, N;
long long answer, sumx, sumy;
pair<int, int> xy[25];

void dfs(int n, int i, long long x, long long y) {
	if (n == N / 2) {
		answer = min(answer, (sumx - 2 * x)*(sumx - 2 * x) + (sumy - 2 * y)*(sumy - 2 * y));
		return;
	}
	for (; i < N; i++)
		dfs(n + 1, i + 1, x + xy[i].first, y + xy[i].second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(6);
	cin >> T;
	while (T--) {
		sumx = 0, sumy = 0;
		answer = 9223372036854775807;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> xy[i].first >> xy[i].second;
			sumx += xy[i].first;
			sumy += xy[i].second;
		}
		dfs(0, 0, 0, 0);
		cout << sqrt((double)answer) << "\n";
	}
	return 0;
}