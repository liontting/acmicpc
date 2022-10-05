#include <iostream>
using namespace std;
int N, M, A[10010], sum[10010], hap, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		hap += A[i];
		sum[i] = hap;
	}
	int mem = 0;
	for (int i = 0; i <= N; i++) {
		while (sum[i] - sum[mem] >= M) {
			if (sum[i] - sum[mem] == M)
				answer++;
			mem++;
		}
	}
	cout << answer;
	return 0;
}