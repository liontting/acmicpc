#include <iostream>
#include <string>
using namespace std;
int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int check = 0;
		string radio;
		cin >> radio;
		for (int i = 0; i < (int)radio.length(); i++) {
			if (radio[i] == '1') {
				if (check == 0 || check == 7)
					check = 1;
				else if (check == 3)
					check = 4;
				else if (check == 4 || check == 5)
					check = 5;
				else if (check == 6 || check == 8)
					check = 7;
				else
					break;
			}
			else {
				if (check == 0 || check == 4 || check == 7)
					check = 6;
				else if (check == 1)
					check = 2;
				else if (check == 2 || check == 3)
					check = 3;
				else if (check == 5)
					check = 8;
				else if (check == 8)
					check = 3;
				else
					break;
			}
		}
		if (check == 4 || check == 5 || check == 7)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}