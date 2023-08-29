#include <iostream>
#include <algorithm>
using namespace std;
int T, N, answer;
char MBTI[100010][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		answer = 10000;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 4; j++)
				cin >> MBTI[i][j];
		if (N > 32)
			cout << "0\n";
		else {
			for (int i = 0; i < N - 2; i++) {
				for (int j = i + 1; j < N - 1; j++) {
					for (int k = j + 1; k < N; k++) {
						int cnt = 0;
						for (int m = 0; m < 4; m++) {
							if (MBTI[i][m] != MBTI[j][m])
								cnt++;
							if (MBTI[j][m] != MBTI[k][m])
								cnt++;
							if (MBTI[k][m] != MBTI[i][m])
								cnt++;
						}
						answer = min(answer, cnt);
					}
				}
			}
			cout << answer << "\n";
		}
	}
	return 0;
}