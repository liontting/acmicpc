#include <iostream>
#include <deque>
using namespace std;
int N, command, X;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> command;
		if (command == 1) {
			cin >> X;
			dq.push_front(X);
		}
		else if (command == 2) {
			cin >> X;
			dq.push_back(X);
		}
		else if (command == 3) {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (command == 4) {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (command == 5) {
			cout << dq.size() << "\n";
		}
		else if (command == 6) {
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == 7) {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << "\n";
		}
		else if (command == 8) {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << "\n";
		}
	}
	return 0;
}