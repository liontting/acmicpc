#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int N, c, M, box[10010], answer;
vector<int> crane;
map <int, int> cnt, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		cnt[c]++;
		if (cnt[c] == 1)
			crane.push_back(c);
	}
	sort(crane.begin(), crane.end(), greater<>());
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> box[i];
	sort(box, box + M);
	if (box[M - 1] > crane[0])
		cout << "-1";
	else {
		int idx = (int)crane.size() - 1;
		for (int i = 0; i < M; i++) {
			while (box[i] > crane[idx])
				idx--;
			m[crane[idx]]++;
		}
		int s = 0, n = 0;
		answer = ceil((float)M / N);
		for (int i = 0; i < (int)crane.size(); i++) {
			n += cnt[crane[i]];
			s += m[crane[i]];
			answer = max(answer, (int)ceil((float)s / n));
		}
		cout << answer;
	}
	return 0;
}