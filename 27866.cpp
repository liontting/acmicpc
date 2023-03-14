#include <iostream>
using namespace std;
char s[1010];
int i;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cin >> i;
	cout << s[i - 1];
	return 0;
}