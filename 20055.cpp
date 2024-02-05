#include <iostream>
#include <deque>
using namespace std;
int N, K, answer;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int A;
		cin >> A;
		dq.push_back({ A, 0 });
	}
	while (1) {
		answer++;

		pair<int, int> n = dq.back();
		dq.pop_back();
		dq.push_front(n);
		dq[N - 1].second = 0;

		for (int i = N - 2; i >= 0; i--) {
			if (dq[i].second && !dq[i + 1].second && dq[i + 1].first) {
				dq[i].second = 0;
				dq[i + 1].first--;
				if (i == N - 2)
					continue;
				dq[i + 1].second = 1;
			}
		}

		if (dq[0].first) {
			dq[0].first--;
			dq[0].second = 1;
		}

		int num = 0;
		for (int i = 0; i < 2 * N; i++)
			if (!dq[i].first)
				num++;
		if (num >= K)
			break;
	}
	cout << answer;
	return 0;
}