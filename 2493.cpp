#include <iostream>
#include <stack>
using namespace std;
int N, tower[500010], answer[500010];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> tower[i];
	for (int i = N; i > 0; i--) {
		while (!s.empty() && tower[i] > tower[s.top()]) {
			answer[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= N; i++)
		cout << answer[i] << " ";
	return 0;
}