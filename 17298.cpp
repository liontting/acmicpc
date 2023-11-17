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
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= A[i])
			s.pop();
		if (s.empty())
			answer[i] = -1;
		else
			answer[i] = s.top();
		s.push(A[i]);
	}
	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	return 0;
}