#include <iostream>
using namespace std;
int T, S;

int main() {
	cin >> T >> S;
	if (S == 1 || (T <= 11 || T > 16))
		cout << "280";
	else if ((T >= 12 && T <= 16) && S == 0)
		cout << "320";
	return 0;
}