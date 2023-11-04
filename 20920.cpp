#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int N, M, num;

struct cmp {
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
		if (a.second == b.second) {
			if (a.first.length() == b.first.length()) {
				if (a > b)
					return 0;
				else
					return 1;
			}
			else if (a.first.length() > b.first.length())
				return 1;
			else
				return 0;
		}
		else if (a.second > b.second)
			return 1;
		else
			return 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int> m;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if ((int)s.length() < M)
			continue;
		m[s]++;
	}
	set<pair<string, int>, cmp> st;
	for (auto iter = m.begin(); iter != m.end(); iter++)
		st.insert(*iter);
	for (auto iter = st.begin(); iter != st.end(); iter++)
		cout << iter->first << "\n";
	return 0;
}