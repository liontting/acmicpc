#include <iostream>
#include <math.h>
using namespace std;
int N;
double answer, x[10010], y[10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	x[N] = x[0];
	y[N] = y[0];
	for (int i = 0; i < N; i++)
		answer += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
	answer = abs(answer) / 2;
	cout << fixed;
	cout.precision(1);
	cout << answer;
	return 0;
}