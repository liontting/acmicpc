#include <iostream>
#include <map>
using namespace std;
int N, K;
long long A[200010], answer;
map<long long, long long> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	m[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
		if (m[A[i] - K] > 0)
			answer += m[A[i] - K];
		m[A[i]]++;
	}
	cout << answer;
	return 0;
}