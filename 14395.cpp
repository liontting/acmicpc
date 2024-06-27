#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
long long s, t, check;
queue<pair<string, long long>> q;
set<long long> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s >> t;
	c.insert(s);
	if (s == t) {
		cout << "0";
		return 0;
	}
	else if (s > t)
		q.push({"/", 1});
	else {
		q.push({"*", s * s});
		q.push({"+", s + s});
		q.push({"/", 1});
	}
	while (!q.empty()) {
		string str = q.front().first;
		long long n = q.front().second;
		c.insert(n);
		q.pop();
		if (n > t)
			continue;
		if (n == t) {
			cout << str;
			check = 1;
			break;
		}
		if (c.find(n * n) == c.end())
			q.push({str + "*", n * n});
		if (c.find(n + n) == c.end())
			q.push({str + "+", n + n});
	}
	if (!check)
		cout << "-1";
	return 0;
}