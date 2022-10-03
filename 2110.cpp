#include <iostream>
#include <algorithm>
using namespace std;
int N, C, X[200010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> X[i];
	sort(X, X + N);
	int left = 1, right = X[N - 1] - X[0];
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int mem = 0;
		for (int i = 0; i < N; i++) {
			if (X[i] - X[mem] >= mid) {
				cnt++;
				mem = i;
			}
		}
		if (cnt >= C) {
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << answer;
	return 0;
}