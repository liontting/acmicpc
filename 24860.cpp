#include <iostream>
using namespace std;
long long int vk, jk, v, j, vh, dh, jh;

int main() {
	cin >> vk >> jk;
	cin >> v >> j;
	cin >> vh >> dh >> jh;
	cout << (vk * jk + v * j)*vh*dh*jh;
	return 0;
}