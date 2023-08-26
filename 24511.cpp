#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int N, A[100010], B, M, C;
queue<int> q;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B;
		if (!A[i])
			s.push(B);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> C;
		q.push(C);
		if (s.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		else {
			cout << s.top() << " ";
			s.pop();
		}
	}
	return 0;
}