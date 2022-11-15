#include <iostream>
using namespace std;
int num, swit[110], student;

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> swit[i];
	cin >> student;
	while (student--) {
		int sex, n;
		cin >> sex >> n;
		if (sex == 1) {
			for (int i = n; i <= num; i += n)
				swit[i] = !swit[i];
		}
		else {
			swit[n] = !swit[n];
			for (int i = 1; swit[n + i] == swit[n - i]; i++) {
				if (n + i > num || n - i < 1)
					break;
				swit[n - i] = !swit[n - i];
				swit[n + i] = !swit[n + i];
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		cout << swit[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}
	return 0;
}