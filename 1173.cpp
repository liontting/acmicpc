#include <iostream>
using namespace std;
int N, m, M, T, R, answer, time, check, now;

int main() {
	cin >> N >> m >> M >> T >> R;
	now = m;
	if (now + T > M) {
		cout << "-1";
		return 0;
	}
	while (time < N) {
		if (now + T <= M) {
			answer++;
			time++;
			now += T;
		}
		else if (now - R >= m) {
			answer++;
			now -= R;
		}
		else {
			answer++;
			now = m;
		}
	}
	cout << answer;
	return 0;
}