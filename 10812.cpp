#include <iostream>
using namespace std;
int N, M, basket[110], temp[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		basket[i] = i;
	while (M--) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int l = 0; l < k - i; l++)
			temp[l] = basket[l + i];
		for (int l = k; l <= j; l++)
			basket[l - k + i] = basket[l];
		for (int l = 0; l < k - i; l++)
			basket[j - l] = temp[k - i - l - 1];
	}
	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
	return 0;
}