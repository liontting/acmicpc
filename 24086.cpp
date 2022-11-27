#include <iostream>
#include <math.h>
using namespace std;
int A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A;
	cin >> B;
	cout << abs(A - B);
	return 0;
}