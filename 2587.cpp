#include <iostream>
#include <algorithm>
using namespace std;
int num[10], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + 5);
	cout << sum / 5 << "\n" << num[2];
	return 0;
}