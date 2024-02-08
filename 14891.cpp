#include <iostream>
using namespace std;
int gear[5][10], K, d[5][5], visited[5];
char temp[5][10];

void rotate(int num, int direction) {
	if (visited[num])
		return;
	visited[num] = 1;
	if (num != 4)
		if (gear[num][d[num][1]] != gear[num + 1][d[num + 1][2]])
			rotate(num + 1, -direction);
	if (num != 1)
		if (gear[num][d[num][2]] != gear[num - 1][d[num - 1][1]])
			rotate(num - 1, -direction);
	d[num][0] = (d[num][0] - direction) % 8;
	d[num][1] = (d[num][1] - direction) % 8;
	d[num][2] = (d[num][2] - direction) % 8;
	for (int i = 0; i < 3; i++)
		if (d[num][i] == -1)
			d[num][i] = 7;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> temp[i][j];
			gear[i][j] = temp[i][j] - '0';
		}
	}
	for (int i = 1; i <= 4; i++)
		d[i][0] = 0, d[i][1] = 2, d[i][2] = 6;
	cin >> K;
	while (K--) {
		int num, direction;
		cin >> num >> direction;
		for (int i = 1; i <= 4; i++)
			visited[i] = 0;
		rotate(num, direction);
	}
	cout << gear[1][d[1][0]] + 2 * gear[2][d[2][0]] + 4 * gear[3][d[3][0]] + 8 * gear[4][d[4][0]];
	return 0;
}