#include <iostream>
#include <algorithm>
using namespace std;
int N, H, obstacle1[100010], obstacle2[100010], answer[200010], minnum = 200000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++)
		cin >> obstacle1[i] >> obstacle2[i];
	sort(obstacle1, obstacle1 + N / 2);
	sort(obstacle2, obstacle2 + N / 2);
	int now = N / 2, left = 0, right = N / 2 - 1;
	for (int i = 0; i < H; i++) {
		while (i + 0.5 > obstacle1[left] && left <= N / 2 - 1) {
			left++;
			now--;
		}
		while (H - (i + 0.5) < obstacle2[right] && right >= 0) {
			right--;
			now++;
		}
		minnum = min(minnum, now);
		answer[now]++;
	}
	cout << minnum << " " << answer[minnum];
	return 0;
}
