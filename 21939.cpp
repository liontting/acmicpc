#include <iostream>
#include <string>
#include <set>
using namespace std;
int N, M, x, p, l, pl[100010];
string command;
set<pair<int,int>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p >> l;
		s.insert({ l,p });
		pl[p] = l;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (!command.compare("recommend")) {
			cin >> x;
			if (x == 1)
				cout << (*s.rbegin()).second << "\n";
			else
				cout << (*s.begin()).second << "\n";
		}
		else if (!command.compare("add")) {
			cin >> p >> l;
			s.insert({ l,p });
			pl[p] = l;
		}
		else if (!command.compare("solved")) {
			cin >> p;
			l = pl[p];
			s.erase(s.find({ l,p }));
		}
	}
	return 0;
}