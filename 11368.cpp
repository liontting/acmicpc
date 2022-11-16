#include <iostream>
using namespace std;
int C, W, L, P;

int main() {
	while (1) {
		int answer = 1;
		cin >> C >> W >> L >> P;
		if (!C && !W && !L && !P)
			break;
		for (int i = 0; i < W*L*P; i++)
			answer *= C;
		cout << answer << "\n";
	}
	return 0;
}