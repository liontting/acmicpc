#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, maxnum;
char table[1010][1010];
vector<vector<char>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = R - 1; i >= 0; i--)
		for (int j = 0; j < C; j++)
			cin >> table[j][i];
	for (int i = 0; i < C; i++) {
		vector<char> temp;
		for (int j = 0; j < R; j++)
			temp.push_back(table[i][j]);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < C - 1; i++) {
		int ans = 0;
		for (int j = 0; j < R; j++) {
			if (v[i][j] != v[i + 1][j])
				break;
			ans++;
		}
		maxnum = max(maxnum, ans);
	}
	cout << R - maxnum - 1;
	return 0;
}