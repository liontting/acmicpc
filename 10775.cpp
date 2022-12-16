#include <iostream>
using namespace std;
int G, P, airplane[100010], root[100010], answer;

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void uni(int x, int y) {
	root[find(x)] = find(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> G;
	cin >> P;
	for (int i = 0; i < P; i++)
		cin >> airplane[i];
	for (int i = 1; i <= G; i++)
		root[i] = i;
	for (int i = 0; i < P; i++) {
		int x = find(airplane[i]);
		if (x == 0)
			break;
		uni(x, x - 1);
		answer++;
	}
	cout << answer;
	return 0;
}