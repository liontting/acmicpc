#include <iostream>
#include <map>
using namespace std;
int N, S, num[50];
long long answer;
map<int, int> sum;

void left(int n, int s) {
	if (n == N / 2) {
		sum[s]++;
		return;
	}
	left(n + 1, s + num[n]);
	left(n + 1, s);
}

void right(int n, int s) {
	if (n == N) {
		answer += sum[S - s];
		return;
	}
	right(n + 1, s + num[n]);
	right(n + 1, s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	left(0, 0);
	right(N / 2, 0);
	if (!S)
		cout << answer - 1;
	else
		cout << answer;
	return 0;
}