#include <iostream>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cout << N / 100 * 78 << " " << N / 5 * 4 + N / 500 * 78;
	return 0;
}