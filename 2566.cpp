#include <iostream>
using namespace std;
int num[10][10], answer = -1, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> num[i][j];
			if (answer < num[i][j]) {
				answer = num[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << answer << "\n";
	cout << x << " " << y;
	return 0;
}