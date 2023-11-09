#include <iostream>
#include <string>
using namespace std;
string s;
int q, sum[27][200010], l, r;
char c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 1; i <= (int)s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (j == s[i - 1] - 'a')
				sum[j][i] = sum[j][i - 1] + 1;
			else
				sum[j][i] = sum[j][i - 1];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> c >> l >> r;
		cout << sum[c - 'a'][r + 1] - sum[c - 'a'][l] << "\n";
	}
	return 0;
}