#include <iostream>
using namespace std;
int N, K, day[100010], sum[100010], hap, answer = -1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> day[i];
		hap += day[i];
		sum[i] = hap;
	}
	int mem = 0;
	for (int i = K; i <= N; i++) {
		if (answer < sum[i] - sum[mem])
			answer = sum[i] - sum[mem];
		mem++;
	}
	cout << answer;
	return 0;
}