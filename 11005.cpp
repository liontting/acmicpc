#include <iostream>
#include <string.h>
using namespace std;
int N, B, ans[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> B;
	int idx = 0;
	while (N) {
		ans[idx] = N % B;
		N -= ans[idx];
		N /= B;
		idx++;
	}
	for (int i = idx - 1; i >= 0; i--) {
		if (ans[i] >= 0 && ans[i] <= 9)
			cout << ans[i];
		else
			cout << (char)(ans[i] + 'A' - 10);
	}
	return 0;
}