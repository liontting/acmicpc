#include <iostream>
#include <algorithm>
using namespace std;
int N, H, height[500010], answer[200010], minnum = 200000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int a, b;
		cin >> a >> b;
		height[a]--;
		height[H - b]++;
	}
	int now = N / 2;
	for (int i = 0; i < H; i++) {
		now += height[i];
		minnum = min(minnum, now);
		answer[now]++;
	}
	cout << minnum << " " << answer[minnum];
	return 0;
}