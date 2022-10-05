#include <iostream>
using namespace std;
int N, S, sequence[100010], sum[100010], hap, minnum = 100010;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> sequence[i];
		hap += sequence[i];
		sum[i] = hap;
	}
	if (hap < S) {
		cout << "0";
		return 0;
	}
	int mem = 0;
	for (int i = 0; i <= N; i++) {
		while (sum[i] - sum[mem] >= S) {
			if (minnum > i - mem)
				minnum = i - mem;
			mem++;
		}
	}
	cout << minnum;
	return 0;
}