#include <iostream>
#include <string>
#include <stack>
using namespace std;
string bracket;
int answer, num = 1;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> bracket;
	for (int i = 0; i < (int)bracket.length(); i++) {
		if (bracket[i] == '(') {
			s.push(2);
			num *= 2;
		}
		else if (bracket[i] == '[') {
			s.push(3);
			num *= 3;
		}
		else if (bracket[i] == ')') {
			if (s.empty() || s.top() != 2) {
				cout << "0";
				return 0;
			}
			if (bracket[i - 1] == '(')
				answer += num;
			s.pop();
			num /= 2;
		}
		else {
			if (s.empty() || s.top() != 3) {
				cout << "0";
				return 0;
			}
			if (bracket[i - 1] == '[')
				answer += num;
			s.pop();
			num /= 3;
		}
	}
	if (!s.empty())
		cout << "0";
	else
		cout << answer;
	return 0;
}