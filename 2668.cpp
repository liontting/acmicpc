#include <iostream>
#include <algorithm>
using namespace std;
int N, table[110], visited1[110], visited2[110], num1, num2, ans[110], answer;

void dfs(int x) {
	ans[answer + num1++] = table[x];
	visited1[x] = 1;
	if (!visited2[table[x]]) {
		num2++;
		visited2[table[x]] = 1;
	}
	if (!visited1[table[x]]) {
		dfs(table[x]);
	}
	visited1[x] = 0;
	visited2[table[x]] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> table[i];
	for (int i = 1; i <= N; i++) {
		int check = 0;
		for (int j = 0; j < answer; j++)
			if (i == ans[j])
				check = 1;
		if (!visited1[i] && !check) {
			dfs(i);
			if (num1 == num2)
				answer += num1;
			num1 = 0;
			num2 = 0;
		}
	}
	sort(ans, ans + answer);
	cout << answer << "\n";
	for (int i = 0; i < answer; i++)
		cout << ans[i] << "\n";
	return 0;
}