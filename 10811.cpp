#include <iostream>
using namespace std;
int N, M, basket[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		basket[i] = i;
	while (M--) {
		int i, j, tmp;
		cin >> i >> j;
		for (int k = 0; k <= (j - i) / 2; k++) {
			tmp = basket[i + k];
			basket[i + k] = basket[j - k];
			basket[j - k] = tmp;
		}
	}
	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
	return 0;
}