#include <iostream>
#include <string>
#include <set>
using namespace std;
int N, num = 0;
set <string> s;
string ss, enter = "ENTER";

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ss;
		if (!ss.compare(enter)) {
			num += s.size();
			s.clear();
		}
		else
			s.insert(ss);
	}
	num += s.size();
	cout << num;
	return 0;
}