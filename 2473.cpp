#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
long long int solution[5010], first, second, third, answer = 3000000010;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> solution[i];
	sort(solution, solution + N);
	for (int i = 0; i < N - 2; i++) {
		int left = i + 1, right = N - 1;
		while (left < right) {
			long long int mid = solution[i] + solution[left] + solution[right];
			if (answer > abs(mid)) {
				first = solution[i];
				second = solution[left];
				third = solution[right];
				answer = abs(mid);
			}
			if (mid < 0)
				left++;
			else
				right--;
		}
	}
	cout << first << " " << second << " " << third;
	return 0;
}