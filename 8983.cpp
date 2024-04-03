#include <iostream>
#include <algorithm>
using namespace std;
int M, N, L, x[100010], answer, line[100010], ln;
pair<int, int> animal[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> L;
	for (int i = 0; i < M; i++)
		cin >> x[i];
	for (int i = 0; i < N; i++)
		cin >> animal[i].first >> animal[i].second;
	sort(x, x + M);
	sort(animal, animal + N);
	for (int i = 0; i < M - 1; i++)
		line[i] = (x[i] + x[i + 1]) / 2;
	line[M - 1] = 1000000000;
	for (int i = 0; i < N; i++) {
		while (line[ln] < animal[i].first)
			ln++;
		if (abs(x[ln] - animal[i].first) + animal[i].second <= L)
			answer++;
	}
	cout << answer;
	return 0;
}