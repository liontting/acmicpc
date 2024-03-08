#include <iostream>
using namespace std;
int N, M, ans;

int f(int a, int b) {
	if (!a || !b || !(a % b))
		return ans;
	if (a > b)
		a %= b;
	int x = b / a;
	if (!(b % a))
		x--;
	ans += x * a;
	return f(a, b - x * a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cout << f(N, M);
	return 0;
}