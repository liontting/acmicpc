#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[200010], B[200010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		if (binary_search(A, A + N, B[i]))
			answer++;
	}
	cout << N + M - 2 * answer;
}