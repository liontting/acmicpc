#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s;
stack<char> op;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << s[i];
		else if (s[i] == '(')
			op.push(s[i]);
		else if (s[i] == '*' || s[i] == '/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				cout << op.top();
				op.pop();
			}
			op.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!op.empty() && op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.push(s[i]);
		}
		else {
			while (op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}