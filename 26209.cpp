#include <iostream>
using namespace std;
int n, answer = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 8; i++) {
		cin >> n;
		if (n == 9)
			answer = 0;
	}
	if (answer)
		cout << "S";
	else
		cout << "F";
	return 0;
}