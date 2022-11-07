#include <iostream>
using namespace std;
int T, n, num[100010], visited[100010], check[100010], answer;

void dfs(int now) {
	visited[now] = 1;
	int next = num[now];
	if (!visited[next])
		dfs(next);
	else {
		if (!check[next]) {
			for (int i = next; i != now; i = num[i])
				answer++;
			answer++;
		}
	}
	check[now] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> num[i];
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
			check[i] = 0;
		}
		answer = 0;
		for (int i = 1; i <= n; i++)
			if(!visited[i])
				dfs(i);
		cout << n - answer << "\n";
	}
	return 0;
}