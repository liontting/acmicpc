#include <iostream>
using namespace std;
int N, factor;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	factor = 2;
	while (N != 1) {
		if (N % factor == 0) {
			cout << factor << "\n";
			N /= factor;
		}
		else
			factor++;
	}
	return 0;
}