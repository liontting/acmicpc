#include <iostream>
#include <vector>
using namespace std;
int N, x[100010], answer[1000010], check[1000010];
vector<int> v[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		check[x[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j * j <= x[i]; j++) {
			if (x[i] % j == 0)
				v[i].push_back(j);
			if (j * j != x[i] && x[i] % j == 0)
				v[i].push_back(x[i] / j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (auto j : v[i]) {
			if (check[j] == 1) {
				answer[j]++;
				answer[x[i]]--;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << answer[x[i]] << " ";
	return 0;
}