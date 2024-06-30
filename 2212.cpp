#include <iostream>
#include <algorithm>
using namespace std;
int N, K, sensor[10010], diff[10010], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
		cin >> sensor[i];
	sort(sensor, sensor + N);
	for (int i = 0; i < N - 1; i++)
		diff[i] = sensor[i + 1] - sensor[i];
	sort(diff, diff + N - 1);
	for (int i = 0; i < N - K; i++)
		answer += diff[i];
	cout << answer;
	return 0;
}