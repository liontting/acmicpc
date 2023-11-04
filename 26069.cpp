#include <iostream>
#include <string>
#include <set>
using namespace std;
int N;
set<string> st;
string s1, s2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		if (!s1.compare("ChongChong") || !s2.compare("ChongChong") || (st.find(s1) != st.end()) || (st.find(s2) != st.end())) {
			st.insert(s1);
			st.insert(s2);
		}
	}
	cout << st.size();
	return 0;
}