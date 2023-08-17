#include <iostream>
#include <stack>
using namespace std;
stack<int> tmp;
int N, last, check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (last + 1 == num)
			last = num;
		else {
			while (!tmp.empty() && (last + 1 == tmp.top())) {
				last = tmp.top();
				tmp.pop();
			}
			tmp.push(num);
		}
	}
	while (!tmp.empty()) {
		if (last + 1 == tmp.top()) {
			last = tmp.top();
			tmp.pop();
		}
		else {
			check = 1;
			break;
		}
	}
	if (!check)
		cout << "Nice";
	else
		cout << "Sad";
	return 0;
}