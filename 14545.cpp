#include <iostream>
using namespace std;
int P, I;

int main() {
	cin >> P;
	while (P--) {
		int answer = 0;
		cin >> I;
		for (int i = 1; i <= I; i++)
			answer += i * i;
		cout << answer << "\n";
	}
	return 0;
}