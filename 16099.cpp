#include <iostream>
using namespace std;
int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		long long lt, wt, le, we;
		cin >> lt >> wt >> le >> we;
		if (lt * wt < le * we)
			cout << "Eurecom\n";
		else if (lt * wt == le * we)
			cout << "Tie\n";
		else
			cout << "TelecomParisTech\n";
	}
	return 0;
}