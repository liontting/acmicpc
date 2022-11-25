#include <iostream>
using namespace std;

int main() {
	int first, second, third;
	cin >> first >> second >> third;
	if (first + second == third)
		cout << first << "+" << second << "=" << third;
	else if (first - second == third)
		cout << first << "-" << second << "=" << third;
	else if (first * second == third)
		cout << first << "*" << second << "=" << third;
	else if (first == second + third)
		cout << first << "=" << second << "+" << third;
	else if (first == second - third)
		cout << first << "=" << second << "-" << third;
	else if (first == second * third)
		cout << first << "=" << second << "*" << third;
	else if (first / second == third && first % second == 0)
		cout << first << "/" << second << "=" << third;
	else
		cout << first << "=" << second << "/" << third;
	return 0;
}