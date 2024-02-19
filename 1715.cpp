#include <iostream>
#include <queue>
using namespace std;
int N, sum;
priority_queue <int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(-num);
	}
	while (pq.size() != 1) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		sum += first + second;
		pq.push(first + second);
	}
	cout << -sum;
	return 0;
}