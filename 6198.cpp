#include <iostream>
#include <stack>
using namespace std;
int N, A[80010];
long long int answer;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= A[i])
			s.pop();
		answer += s.size();
		s.push(A[i]);
	}
	cout << answer;
	return 0;
}