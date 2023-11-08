#include <iostream>
#include <algorithm>
using namespace std;
int n, pole[510], DP[510], maxnum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int A, B;
		cin >> A >> B;
		pole[A] = B;
	}
	for (int i = 1; i <= 500; i++) {
		int cur = 0;
		for (int j = 1; j < i; j++)
			if (pole[j] < pole[i] && DP[cur] < DP[j])
				cur = j;
		if (pole[i])
			maxnum = max(maxnum, (DP[i] = DP[cur] + 1));
	}
	cout << n - maxnum;
	return 0;
}