#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int X, Y, D, T;
double dist, time;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	cin >> X >> Y >> D >> T;
	dist = sqrt(X * X + Y * Y);
	if (T > D)
		cout << dist;
	else {
		int jump = (int)(dist / D);
		time = dist;
		dist -= jump * D;
		if (jump == 0) // 걸어서, 점프+걸어서, 점프
			time = min(time, min(T + (D - dist), 2.0 * T));
		else
			time = min(time, min(jump * T + dist, (jump + 1.0) * T));
		cout << time;
	}
	return 0;
}