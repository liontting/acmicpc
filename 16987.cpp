#include <iostream>
#include <algorithm>
using namespace std;
int N, dp[8][8][8], answer;
pair<int, int> egg[10];

void bt(int n) {
	if (n == N) {
		int ans = 0;
		for (int i = 0; i < N; i++)
			if (egg[i].first <= 0)
				ans++;
		answer = max(answer, ans);
		return;
	}
	if (egg[n].first <= 0) {
		bt(n + 1);
		return;
	}
	int check = 0;
	for (int i = 0; i < N; i++) {
		if (i != n && egg[i].first > 0) {
			check = 1;
			egg[n].first -= egg[i].second;
			egg[i].first -= egg[n].second;
			bt(n + 1);
			egg[n].first += egg[i].second;
			egg[i].first += egg[n].second;
		}
	}
	if (!check)
		bt(n + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> egg[i].first >> egg[i].second;
	bt(0);
	cout << answer;
	return 0;
}