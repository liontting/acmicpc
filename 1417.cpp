#include <iostream>
#include <queue>
using namespace std;
int N, dasom, answer;
priority_queue<int> pq;

int main() {
	cin >> N;
	cin >> dasom;
	for (int i = 0; i < N - 1; i++) {
		int candidate;
		cin >> candidate;
		pq.push(candidate);
	}
	while (!pq.empty() && dasom <= pq.top()) {
		int top = pq.top();
		pq.pop();
		dasom++;
		top--;
		answer++;
		pq.push(top);
	}
	cout << answer;
	return 0;
}