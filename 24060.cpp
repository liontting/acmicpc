#include <iostream>
using namespace std;
int N, K, A[500010], tmp[500010], num, answer = -1;

void merge(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
	while (i <= q and j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}
	while (i <= q)
		tmp[t++] = A[i++];
	while (j <= r)
		tmp[t++] = A[j++];
	i = p;
	t = 1;
	while (i <= r) {
		num++;
		if (num == K)
			answer = tmp[t];
		A[i++] = tmp[t++];
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	merge_sort(0, N - 1);
	cout << answer;
}