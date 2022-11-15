#include <iostream>
#include <math.h>
using namespace std;
int T, x1, y, x2, y2, n;

int main() {
	cin >> T;
	while (T--) {
		int answer = 0;
		cin >> x1 >> y >> x2 >> y2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int cx, cy, r, c1 = 0, c2 = 0;
			cin >> cx >> cy >> r;
			if ((pow(abs(cx - x1), 2) + pow(abs(cy - y), 2)) <= pow(r, 2))
				c1 = 1;
			if ((pow(abs(cx - x2), 2) + pow(abs(cy - y2), 2)) <= pow(r, 2))
				c2 = 1;
			if (c1 != c2)
				answer++;
		}
		cout << answer << "\n";
	}
	return 0;
}