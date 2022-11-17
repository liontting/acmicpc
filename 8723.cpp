#include <iostream>
#include <math.h>
using namespace std;
int a, b, c;

int main() {
	cin >> a >> b >> c;
	if (a == b && b == c)
		cout << "2";
	else {
		if (pow(a, 2) + pow(b, 2) == pow(c, 2))
			cout << "1";
		else if (pow(b, 2) + pow(c, 2) == pow(a, 2))
			cout << "1";
		else if (pow(c, 2) + pow(a, 2) == pow(b, 2))
			cout << "1";
		else
			cout << "0";
	}
	return 0;
}