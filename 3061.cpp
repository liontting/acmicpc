#include <iostream>
using namespace std;
int T, N, a[1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1-i; j++) {
				if (a[j] > a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}