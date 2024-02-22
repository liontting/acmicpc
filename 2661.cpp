#include <iostream>
using namespace std;
int N, num[100];

int check(int n) {
	for (int i = 2; i <= (n + 1) / 2; i++) {
		for (int j = 0; j <= n + 1 - 2 * i; j++) {
			int c = 0;
			for (int k = j; k < j + i; k++)
				if (num[k] == num[i + k])
					c++;
			if (c == i)
				return 1;
		}
	}
	return 0;
}

void bt(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++)
			cout << num[i];
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		if (!n || num[n - 1] != i) {
			num[n] = i;
			if (!check(n))
				bt(n + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	bt(0);
	return 0;
}