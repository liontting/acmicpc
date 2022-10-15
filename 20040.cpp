#include <iostream>
using namespace std;
int n, m, root[500010], answer;

int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void uni(int x, int y) {
	if (find(x) != find(y))
		root[find(x)] = find(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		root[i] = i;
	for (int i = 1; i <= m; i++) {
		int s, e;
		cin >> s >> e;
		if (find(s) == find(e) && !answer)
			answer = i;
		uni(s, e);
	}
	cout << answer;
	return 0;
}