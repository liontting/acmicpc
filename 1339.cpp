#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, alphabet[30], answer;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
    while (N--) {
        cin >> s;
        for (int i = s.length() - 1, temp = 1; i >= 0; i--, temp *= 10)
            alphabet[s[i] - 'A'] += temp;
    }
    sort(alphabet, alphabet + 26);
    for (int i = 25, n = 9; n; i--, n--)
        answer += n * alphabet[i];
    cout << answer;
	return 0;
}