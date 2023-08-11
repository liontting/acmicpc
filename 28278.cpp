#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		int c, x;
		cin >> c;
		if (c == 1) {
			cin >> x;
			s.push(x);
		}
		else if (c == 2) {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << "-1\n";
		}
		else if (c == 3) {
			cout << s.size() << "\n";
		}
		else if (c == 4) {
			if (!s.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (c == 5) {
			if (!s.empty())
				cout << s.top() << "\n";
			else
				cout << "-1\n";
		}
	}
	return 0;
}