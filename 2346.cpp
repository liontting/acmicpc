#include <iostream>
#include <deque>
using namespace std;
int N, balloon;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> balloon;
		dq.push_back(make_pair(balloon, i));
	}
	while (!dq.empty()) {
		pair<int, int> tmp = dq.front();
		cout << tmp.second << " ";
		dq.pop_front();
		if (dq.empty())
			break;
		if (tmp.first > 0) {
			for (int i = 1; i < tmp.first; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < -tmp.first; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	return 0;
}