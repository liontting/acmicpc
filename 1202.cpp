#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, C[300010], idx;
long long answer;
pair<int, int> MV[300010];
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> MV[i].first >> MV[i].second;
	for (int i = 0; i < K; i++)
		cin >> C[i];
	sort(MV, MV + N);
	sort(C, C + K);
	for (int i = 0; i < K; i++) {
		while (idx < N && MV[idx].first <= C[i])
			pq.push(MV[idx++].second);
		if (pq.size()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
	return 0;
}