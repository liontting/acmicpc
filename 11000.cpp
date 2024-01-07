#include <iostream>
#include <queue>
using namespace std;
int N, answer;
priority_queue<pair<int, int>> pq;
priority_queue<int> in_class;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		pq.push(make_pair(-S, T));
	}
	int s, t = pq.top().second;
	pq.pop();
	in_class.push(-t);
	answer++;
	while (!pq.empty()) {
		s = -pq.top().first;
		t = pq.top().second;
		pq.pop();
		if (-in_class.top() <= s) {
			in_class.pop();
			in_class.push(-t);
		}
		else {
			in_class.push(-t);
			answer++;
		}
	}
	cout << answer;
	return 0;
}