#include <iostream>
#include <algorithm>
using namespace std;
int N, M, answer;
int six = 1001, one = 1001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (x < six)
			six = x;
		if (y < one)
			one = y;
	}
	answer = min((N / 6 + 1) * six, (N / 6) * six + (N % 6) * one);
	answer = min(answer, N * one);
	cout << answer;
	return 0;
}