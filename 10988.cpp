#include <iostream>
#include <string.h>
using namespace std;
char s[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < (int)strlen(s); i++) {
		if (s[i] != s[strlen(s) - i - 1]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
	return 0;
}