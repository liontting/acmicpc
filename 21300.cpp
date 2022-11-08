#include <iostream>
using namespace std;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		sum += n;
	}
	cout << sum * 5;
	return 0;
}