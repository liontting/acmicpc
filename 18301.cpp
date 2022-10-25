#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, n1, n2, n12;
	cin >> n1 >> n2 >> n12;
	N = (n1 + 1)*(n2 + 1) / (n12 + 1) - 1;
	cout << N;
	return 0;
}