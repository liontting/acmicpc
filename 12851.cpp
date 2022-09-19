#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int x[200010], visited[200010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	if (N >= K)
	{
		cout << N - K << "\n";
		cout << 1;
		return 0;
	}
	for (int i = 0; i <= 200000; i++)
		x[i] = 987654321;
	q.push(N);
	visited[N] = 1;
	x[N] = 0;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (x[n] + 1 <= x[n - 1] && n - 1 >= 0) {
			q.push(n - 1);
			if (x[n] + 1 == x[n - 1])
				visited[n - 1]++;
			else
				visited[n - 1] = 1;
			x[n - 1] = x[n] + 1;
		}
		if (x[n] + 1 <= x[n + 1] && n + 1 <= K) {
			q.push(n + 1);
			if (x[n] + 1 == x[n + 1])
				visited[n + 1]++;
			else
				visited[n + 1] = 1;
			x[n + 1] = x[n] + 1;
		}
		if (x[n] + 1 <= x[2 * n] && 2 * n <= 100000) {
			q.push(2 * n);
			if (x[n] + 1 == x[2 * n])
				visited[2 * n]++;
			else
				visited[2 * n] = 1;
			x[2 * n] = x[n] + 1;
		}
	}
	cout << x[K] << "\n";
	cout << visited[K];
	return 0;
}