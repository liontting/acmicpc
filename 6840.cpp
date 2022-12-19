#include <iostream>
using namespace std;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c;
	if (b > a && a > c)
		cout << a;
	else if (c > a && a > b)
		cout << a;
	else if (a > b && b > c)
		cout << b;
	else if (c > b && b > a)
		cout << b;
	else if (a > c && c > b)
		cout << c;
	else
		cout << c;
}