#include <iostream>
using namespace std;
int x[5], y[5];

int ccw(int a, int b, int c) {
	long long int ans = x[a] * y[b] + x[b] * y[c] + x[c] * y[a] - y[a] * x[b] - y[b] * x[c] - y[c] * x[a];
	if (ans > 0)
		return 1;
	else if (ans < 0)
		return -1;
	else
		return 0;
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> x[i] >> y[i];
	int ccw1 = ccw(0, 1, 2) * ccw(0, 1, 3);
	int ccw2 = ccw(2, 3, 0) * ccw(2, 3, 1);
	if (ccw1 < 0 && ccw2 < 0)
		cout << "1";
	else
		cout << "0";
	return 0;
}