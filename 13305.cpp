#include <iostream>
using namespace std;
int N, road[100010], gas[100010];
long long int sum, minnum = 2100000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> road[i];
	for (int i = 0; i < N; i++)
		cin >> gas[i];
	for (int i = 0; i < N - 1; i++) {
		if (minnum > gas[i])
			minnum = gas[i];
		sum += minnum * road[i];
	}
	cout << sum;
	return 0;
}