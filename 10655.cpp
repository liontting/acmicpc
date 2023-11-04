#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N, dist[100010][2], xy[100010][2], sum, minsum = 2100000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> xy[i][0] >> xy[i][1];
		if (i >= 1)
			dist[i][0] = abs(xy[i - 1][0] - xy[i][0]) + abs(xy[i - 1][1] - xy[i][1]);
		if (i >= 2)
			dist[i][1] = abs(xy[i - 2][0] - xy[i][0]) + abs(xy[i - 2][1] - xy[i][1]);
		sum += dist[i][0];
	}
	for (int i = 2; i < N; i++)
		minsum = min(minsum, sum - dist[i - 1][0] - dist[i][0] + dist[i][1]);
	cout << minsum;
	return 0;
}