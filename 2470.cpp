#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N, solution[100010], answer = 2100000000, first, second;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> solution[i];
	sort(solution, solution + N);
	int left = 0, right = N - 1;
	while (left < right) {
		int mid = solution[left] + solution[right];
		if (answer > abs(mid)) {
			first = solution[left];
			second = solution[right];
			answer = abs(mid);
		}
		if (mid < 0)
			left++;
		else
			right--;
	}
	cout << first << " " << second;
	return 0;
}