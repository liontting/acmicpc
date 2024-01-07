#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, answer, cnt;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		v.push_back(make_pair(S, 1));
		v.push_back(make_pair(T, 0));
	}
	sort(v.begin(), v.end());
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		if (iter->second)
			cnt++;
		else
			cnt--;
		answer = max(answer, cnt);
	}
	cout << answer;
	return 0;
}