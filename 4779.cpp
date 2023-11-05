#include <iostream>
#include <math.h>
using namespace std;
int N;

void jaegui(int n) {
	if (n == 1) {
		cout << "-";
		return;
	}
	jaegui(n / 3);
	for (int i = 0; i < n / 3; i++)
		cout << " ";
	jaegui(n / 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> N) {
		jaegui((int)pow(3, N));
		cout << "\n";
	}
	return 0;
}