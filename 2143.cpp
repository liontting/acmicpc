#include <iostream>
#include <algorithm>
using namespace std;
int T, n, A[1010], sumA[1000010], m, B[1010], sumB[1000010];
long long int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	int idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			sumA[idx++] = sum;
		}
	}
	idx = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			sumB[idx++] = sum;
		}
	}

	sort(sumA, sumA + n * (n + 1) / 2);
	sort(sumB, sumB + m * (m + 1) / 2);

	long long int a = 0, b = (m * (m + 1) / 2)- 1;
	while (a < n * (n + 1) / 2 && b >= 0) {
		int temp = sumA[a] + sumB[b];
		if (temp == T) {
			long long int acnt = 1, bcnt = 1;
			while (a < (n * (n + 1) / 2) - 1 && sumA[a] == sumA[a + 1]) {
				a++;
				acnt++;
			}
			while (b > 0 && sumB[b] == sumB[b - 1]) {
				b--;
				bcnt++;
			}
			cnt += acnt * bcnt;
			a++;
		}
		else if (temp > T)
			b--;
		else
			a++;
	}
	cout << cnt;
	return 0;
}