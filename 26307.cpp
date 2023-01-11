#include <iostream>
using namespace std;
int HH, MM;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> HH >> MM;
	cout << 60 * (HH - 9) + MM;
	return 0;
}