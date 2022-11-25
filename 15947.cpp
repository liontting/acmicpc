#include <iostream>
using namespace std;
int N;

int main() {
	cin >> N;
	N--;
	if (N % 14 == 0 || N % 14 == 12)
		cout << "baby";
	else if (N % 14 == 1 || N % 14 == 13)
		cout << "sukhwan";
	else if (N % 14 == 4)
		cout << "very";
	else if (N % 14 == 5)
		cout << "cute";
	else if (N % 14 == 8)
		cout << "in";
	else if (N % 14 == 9)
		cout << "bed";
	else if (N % 14 == 2 || N % 14 == 6 || N % 14 == 10) {
		if (N / 14 >= 3) {
			cout << "tu+ru*" << (N / 14 + 2);
		}
		else {
			cout << "tururu";
			for (int i = 0; i < N / 14; i++)
				cout << "ru";
		}
	}
	else {
		if (N / 14 >= 4) {
			cout << "tu+ru*" << (N / 14 + 1);
		}
		else {
			cout << "turu";
			for (int i = 0; i < N / 14; i++)
				cout << "ru";
		}
	}
	return 0;
}