#include <iostream>
#include <algorithm>
using namespace std;
int N, num[55], answer;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);

	int pos = N - 1, neg = 0;
	for (int i = 0; i < N; i++) {
		if (num[i] < 1)
			neg = i;
		if (num[N - 1 - i] > 1)
			pos = N - 1 - i;
	}

	int i, j;
	for (i = 0; i + 1 <= neg; i += 2)
		answer += num[i] * num[i + 1];
	for (j = N - 1; j - 1 >= pos; j -= 2)
		answer += num[j] * num[j - 1];
	for (; i <= j; i++)
		answer += num[i];
	cout << answer;
	return 0;
}
