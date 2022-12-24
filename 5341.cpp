#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n > 0) {
		int answer = 0;
		for (int i = 1; i <= n; i++)
			answer += i;
		cout << answer << "\n";
		cin >> n;
	}
	return 0;
}