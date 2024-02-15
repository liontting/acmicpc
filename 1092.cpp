#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, crane[60], M, b, answer;
vector<int> box;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> crane[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> b;
		box.push_back(b);
	}
	sort(crane, crane + N, greater<>());
	sort(box.begin(), box.end(), greater<>());
	while (answer != -1) {
		answer++;
		int check = 0;
		for (int i = 0; i < N; i++) {
			if (crane[i] < box[(int)box.size() - 1])
				continue;
			for (int j = 0; j < (int)box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					check = 1;
					break;
				}
			}
		}
		if (!box.size())
			break;
		if (!check)
			answer = -1;
	}
	cout << answer;
	return 0;
}