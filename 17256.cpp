#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ax, ay, az, cx, cy, cz, bx, by, bz;
	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;
	bx = cx - az;
	by = cy / ay;
	bz = cz - ax;
	cout << bx << " " << by << " " << bz;
	return 0;
}