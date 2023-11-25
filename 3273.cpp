#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, a[100010], x, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	sort(a, a + n);
	int l = 0, r = n - 1;
	while (l < r) {
		if (x > a[l] + a[r])
			l++;
		else if (x < a[l] + a[r])
			r--;
		else {
			answer++;
			if (abs(a[l] - a[l + 1]) > abs(a[r] - a[r - 1]))
				r--;
			else
				l++;
		}
	}
	cout << answer;
	return 0;
}