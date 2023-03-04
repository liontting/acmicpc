#include <iostream>
using namespace std;
int N, M, basket[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	while (M--) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int a = i; a <= j; a++)
			basket[a] = k;
	}
	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
	return 0;
}