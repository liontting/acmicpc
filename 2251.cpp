#include <iostream>
using namespace std;
int A, B, C, visited[210][210];

void dfs(int a, int b, int c) {
	if (visited[a][c])
		return;
	visited[a][c] = 1;

	if ((A - a) < b)
		dfs(A, b - (A - a), c);
	else
		dfs(a + b, 0, c);
	if ((A - a) < c)
		dfs(A, b, c - (A - a));
	else
		dfs(a + c, b, 0);
	
	if ((B - b) < a)
		dfs(a - (B - b), B, c);
	else
		dfs(0, a + b, c);
	if ((B - b) < c)
		dfs(a, B, c - (B - b));
	else
		dfs(a, b + c, 0);

	if ((C - c) < a)
		dfs(a - (C - c), b, C);
	else
		dfs(0, b, a + c);
	if ((C - c) < b)
		dfs(a, b - (C - c), C);
	else
		dfs(a, 0, b + c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	dfs(0, 0, C);
	for (int i = 0; i <= C; i++)
		if (visited[0][i])
			cout << i << " ";
	return 0;
}