#include <iostream>
#include <algorithm>
using namespace std;
int N, A[2010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < N; i++) {
		long long cur = A[i];
		int l = 0, r = N - 1;
		while (l < r) {
			if (cur == A[l] + A[r]) {
				if (i != l && i != r) {
					answer++;
					break;
				}
				else if (i == l)
					l++;
				else
					r--;
			}
			else if (cur < A[l] + A[r])
				r--;
			else
				l++;
		}
	}
	cout << answer;
	return 0;
}