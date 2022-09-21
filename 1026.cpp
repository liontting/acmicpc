#include <iostream>
#include <algorithm>
using namespace std;
int A[60], B[60], answer;

bool compare(int i, int j) {
	return j < i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + N, compare);
	for (int i = 0; i < N; i++)
		answer += A[i] * B[i];
	cout << answer;
	return 0;
}