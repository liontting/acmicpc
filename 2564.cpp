#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int width, vertical, num, store[2][110], donggeun[2], answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> width >> vertical;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> store[0][i] >> store[1][i];
	cin >> donggeun[0] >> donggeun[1];
	for (int i = 0; i < num; i++) {
		if (store[0][i] == donggeun[0])
			answer += abs(store[1][i] - donggeun[1]);
		else if ((store[0][i] == 1 && donggeun[0] == 2) || (store[0][i] == 2 && donggeun[0] == 1)) {
			answer += vertical;
			answer += min(store[1][i] + donggeun[1], 2 * width - (store[1][i] + donggeun[1]));
		}
		else if ((store[0][i] == 3 && donggeun[0] == 4) || (store[0][i] == 4 && donggeun[0] == 3)) {
			answer += width;
			answer += min(store[1][i] + donggeun[1], 2 * vertical - (store[1][i] + donggeun[1]));
		}
		else if ((store[0][i] == 1 && donggeun[0] == 3) || (store[0][i] == 3 && donggeun[0] == 1))
			answer += store[1][i] + donggeun[1];
		else if (store[0][i] == 1 && donggeun[0] == 4)
			answer += (width - store[1][i]) + donggeun[1];
		else if (store[0][i] == 4 && donggeun[0] == 1)
			answer += store[1][i] + (width - donggeun[1]);
		else if (store[0][i] == 2 && donggeun[0] == 3)
			answer += store[1][i] + (vertical - donggeun[1]);
		else if (store[0][i] == 3 && donggeun[0] == 2)
			answer += (vertical - store[1][i]) + donggeun[1];
		else if (store[0][i] == 2 && donggeun[0] == 4)
			answer += (width - store[1][i]) + (vertical - donggeun[1]);
		else
			answer += (vertical - store[1][i]) + (width - donggeun[1]);
	}
	cout << answer;
	return 0;
}