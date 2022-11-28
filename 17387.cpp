#include <iostream>
#include <algorithm>
using namespace std;
pair<long long int, long long int> xy[5];

int ccw(int a, int b, int c) {
	long long int ans = xy[a].first * xy[b].second + xy[b].first * xy[c].second + xy[c].first * xy[a].second;
	ans = ans - xy[a].second * xy[b].first - xy[b].second * xy[c].first - xy[c].second * xy[a].first;
	if (ans > 0)
		return 1;
	else if (ans < 0)
		return -1;
	else
		return 0;
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> xy[i].first >> xy[i].second;
	int ccw1 = ccw(0, 1, 2) * ccw(0, 1, 3);
	int ccw2 = ccw(2, 3, 0) * ccw(2, 3, 1);
	if (ccw1 <= 0 && ccw2 <= 0) {
		if (ccw1 == 0 && ccw2 == 0) {
			if (xy[0] > xy[1])
				swap(xy[0], xy[1]);
			if (xy[2] > xy[3])
				swap(xy[2], xy[3]);
			if (xy[0] <= xy[3] && xy[2] <= xy[1])
				cout << "1";
			else
				cout << "0";
		}
		else
			cout << "1";
	}
	else
		cout << "0";
	return 0;
}