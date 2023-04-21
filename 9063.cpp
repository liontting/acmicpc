#include <iostream>
#include <stdlib.h>
using namespace std;
int N, minx = 100000, maxx = -100000, miny = 100000, maxy = -100000;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if (minx > x)
			minx = x;
		if (maxx < x)
			maxx = x;
		if (miny > y)
			miny = y;
		if (maxy < y)
			maxy = y;
	}
	cout << abs(maxx - minx)*abs(maxy - miny);
	return 0;
}