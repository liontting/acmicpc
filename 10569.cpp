#include <iostream>
using namespace std;
int T, V, E;

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;
		cout << 2 - V + E << "\n";
	}
	return 0;
}