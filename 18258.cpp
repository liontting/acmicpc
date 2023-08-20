#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, X;
char command[10];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> command;
		if (!strcmp(command, "push")) {
			cin >> X;
			q.push(X);
		}
		else if (!strcmp(command, "pop")) {
			if (q.empty())
				cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (!strcmp(command, "size")) {
			cout << q.size() << "\n";
		}
		else if (!strcmp(command, "empty")) {
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!strcmp(command, "front")) {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (!strcmp(command, "back")) {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}
	return 0;
}