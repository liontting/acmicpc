#include <iostream>
using namespace std;
int N, M, A;
long long int sum, answer, ans[1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A;
		sum += A;
		ans[sum % M]++;
		if (!(sum % M))
			answer++;
	}
	for (int i = 0; i < M; i++)
		if (ans[i] > 1)
			answer += (ans[i] * (ans[i] - 1)) / 2;
	cout << answer;
	return 0;
}