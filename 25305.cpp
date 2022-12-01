#include <iostream>
#include <algorithm>
using namespace std;
int N, k, num[1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> k;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	cout << num[N - k];
	return 0;
}