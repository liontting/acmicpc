#include <iostream>
using namespace std;
int x[5], y[5];
double answer;

int main() {
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	x[3] = x[0];
	y[3] = y[0];
	for (int i = 0; i < 3; i++)
		answer += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
	if (answer / 2 > 0)
		cout << "1";
	else if (answer / 2 < 0)
		cout << "-1";
	else
		cout << "0";
	return 0;
}