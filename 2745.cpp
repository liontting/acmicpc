#include <iostream>
#include <string.h>
using namespace std;
char N[1000];
int B, mul, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> B;
	mul = 1;
	for (int i = (int)strlen(N) - 1; i >= 0; i--) {
		if (N[i] >= '0' && N[i] <= '9') {
			ans += (N[i] - '0') * mul;
			mul *= B;
		}
		else {
			ans += (N[i] - 'A' + 10) * mul;
			mul *= B;
		}
	}
	cout << ans;
	return 0;
}