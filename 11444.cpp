#include <iostream>
#include <map>
using namespace std;
map<long long int, long long int> m;
long long int n;

long long int fibonacci(long long int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return (m[1] = 1);
	else if (num == 2)
		return (m[2] = 1);
	else if (m[num])
		return m[num];
	else {
		if (num % 2 == 0) {
			long long int a = fibonacci(num / 2 - 1);
			long long int b = fibonacci(num / 2);
			m[num] = (a * b) % 1000000007 + (b * (a + b)) % 1000000007;
			return m[num] = m[num] % 1000000007;
		}
		else {
			long long int a = fibonacci(num / 2 + 1);
			long long int b = fibonacci(num / 2);
			m[num] = (a*a) % 1000000007 + (b*b) % 1000000007;
			return m[num] = m[num] % 1000000007;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cout <<	fibonacci(n);
	return 0;
}