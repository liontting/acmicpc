#include <iostream>
#include <math.h>
using namespace std;
double D, H, W, x;

int main() {
	cin >> D >> H >> W;
	x = sqrt((D * D) / (H * H + W * W));
	cout << (int)(H * x) << " " << (int)(W * x);
	return 0;
}