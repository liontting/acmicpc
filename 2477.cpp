#include <iostream>
using namespace std;
int K, direction, length[10], area[10], maxi, maxarea;

int main() {
	cin >> K;
	for (int i = 0; i < 6; i++)
		cin >> direction >> length[i];
	length[6] = length[0];
	for (int i = 0; i < 6; i++) {
		area[i] = length[i] * length[i + 1];
		if (maxarea < area[i]) {
			maxarea = area[i];
			maxi = i;
		}
	}
	cout << K * (maxarea - area[(maxi + 3) % 6]);
	return 0;
}