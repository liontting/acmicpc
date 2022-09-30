#include <iostream>
#include <stack>
#define INF 2100000000
using namespace std;
int N, dp[2][1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		dp[0][i] = INF;
	int i = N;
	while (i > 1) {
		if (dp[0][i - 1] > dp[0][i] + 1) {
			dp[0][i - 1] = dp[0][i] + 1;
			dp[1][i - 1] = i;
		}
		if (i % 2 == 0) {
			if (dp[0][i / 2] > dp[0][i] + 1) {
				dp[0][i / 2] = dp[0][i] + 1;
				dp[1][i / 2] = i;
			}
		}
		if (i % 3 == 0) {
			if (dp[0][i / 3] > dp[0][i] + 1) {
				dp[0][i / 3] = dp[0][i] + 1;
				dp[1][i / 3] = i;
			}
		}
		i--;
	}
	cout << dp[0][1] << "\n";
	stack<int> st;
	while (i != N) {
		st.push(i);
		i = dp[1][i];
	}
	st.push(i);
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}