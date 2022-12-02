#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int T, answer;
char s[1010];

int recursion(const char *s, int l, int r) {
	answer++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		answer = 0;
		cin >> s;
		cout << isPalindrome(s) << " ";
		cout << answer << "\n";
	}
}