#include <iostream>
using namespace std;
int T1, F1, S1, P1, C1;
int T2, F2, S2, P2, C2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T1 >> F1 >> S1 >> P1 >> C1;
	cin >> T2 >> F2 >> S2 >> P2 >> C2;
	cout << 6 * T1 + 3 * F1 + 2 * S1 + P1 + 2 * C1 << " ";
	cout << 6 * T2 + 3 * F2 + 2 * S2 + P2 + 2 * C2;
	return 0;
}