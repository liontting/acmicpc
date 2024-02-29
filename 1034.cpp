#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, M, K, answer;
string lamp[60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> lamp[i];
	cin >> K;
	for (int i = 0; i < N; i++) {
		int cnt = 0, same = 0;
		for (int j = 0; j < M; j++)
			if (lamp[i][j] == '0')
				cnt++;
		if (cnt <= K && !((K - cnt) % 2)) {
			for (int j = 0; j < N; j++) {
				if (lamp[i] == lamp[j])
					same++;
				answer = max(answer, same);
			}
		}
	}
	cout << answer;
	return 0;
}