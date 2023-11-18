#include <iostream>
#include <stack>
using namespace std;
int N, A[1000010], answer[1000010];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		answer[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		while (!s.empty() && A[s.top()] < A[i]) {
			answer[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	return 0;
}