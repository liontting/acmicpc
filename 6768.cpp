#include <iostream>
using namespace std;
int J;

int main() {
	cin >> J;
	if (J < 4)
		cout << "0";
	else {
		cout << ((J - 1)*(J - 2)*(J - 3)) / (3 * 2);
	}
	return 0;
}