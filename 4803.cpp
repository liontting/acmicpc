#include <iostream>
using namespace std;
int n, m, iter = 1, root[510], cycle[510], ans[510];

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
	while (n || m) {
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			root[i] = i;
			cycle[i] = 0;
			ans[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int e1, e2;
			cin >> e1 >> e2;
			if (find(e1) != find(e2)) {
				if (cycle[find(e1)] || cycle[find(e2)])
					cycle[find(e1)] = cycle[find(e2)] = 1;
				uni(e1, e2);
			}
			else
				cycle[find(e1)] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!cycle[find(i)] && !ans[find(i)]) {
				ans[find(i)] = 1;
				answer++;
			}
		}
		cout << "Case " << iter++;
		if (!answer)
			cout << ": No trees.\n";
		else if (answer == 1)
			cout << ": There is one tree.\n";
		else
			cout << ": A forest of " << answer << " trees.\n";
		cin >> n >> m;
	}
	return 0;
}