#include <iostream>
#include <math.h>
using namespace std;
int N, W, H;

int main() {
	cin >> N >> W >> H;
	while (N--) {
		int matches;
		cin >> matches;
		if (pow(matches, 2) > (pow(W, 2) + pow(H, 2)))
			cout << "NE\n";
		else
			cout << "DA\n";
	}
	return 0;
}