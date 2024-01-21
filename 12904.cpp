#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string S, T;
int answer;

void recur(string t) {
	if (S.length() == t.length()) {
		if (!S.compare(t))
			answer = 1;
		return;
	}
	if (t[t.length() - 1] == 'B') {
		t.erase(t.begin() + t.length() - 1);
		reverse(t.begin(), t.end());
		recur(t);
	}
	else {
		t.erase(t.begin() + t.length() - 1);
		recur(t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
	cin >> T;
	recur(T);
	cout << answer;
	return 0;
}