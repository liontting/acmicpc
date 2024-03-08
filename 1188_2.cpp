#include <iostream>
using namespace std;
int N, M, x;

int f(int a, int b) {
	while (b) {
        x = a % b;
        a = b;
        b = x;
    }
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cout << M - f(N, M);
	return 0;
}