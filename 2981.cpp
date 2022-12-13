#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, num[110], answer;
vector<int> v;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	answer = num[1] - num[0];
	for (int i = 2; i < N; i++)
		answer = gcd(answer, num[i] - num[i - 1]);
	for (int i = 1; i * i <= answer; i++) {
		if (answer % i == 0) {
			if (i != 1)
				v.push_back(i);
			if (i != answer / i)
				v.push_back(answer / i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}