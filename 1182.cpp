#include <iostream>
#include <map>
using namespace std;
int N, S, num[30];
map<int, int> sum;

void bt(int n, int s) {
	if (n == N) {
		sum[s]++;
		return;
	}
	bt(n + 1, s + num[n]);
	bt(n + 1, s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	bt(0, 0);
	if (!S)
		cout << sum[S] - 1;
	else
		cout << sum[S];
	return 0;
}