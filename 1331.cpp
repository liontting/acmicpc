#include <iostream>
#include <string>
using namespace std;
int fx, fy, x, y, nx, ny, check, visited[10][10];
string location;

int main() {
	cin >> location;
	fx = location[1] - '1', fy = location[0] - 'A';
	x = fx, y = fy;
	for (int i = 0; i < 36; i++) {
		visited[x][y] = 1;
		if (i != 35) {
			cin >> location;
			nx = location[1] - '1', ny = location[0] - 'A';
			if (visited[nx][ny])
				check = 1;
		}
		else
			nx = fx, ny = fy;
		if ((nx == x + 2) && (ny == y - 1 || ny == y + 1))
			x = nx, y = ny;
		else if ((nx == x + 1) && (ny == y - 2 || ny == y + 2))
			x = nx, y = ny;
		else if ((nx == x - 1) && (ny == y - 2 || ny == y + 2))
			x = nx, y = ny;
		else if ((nx == x - 2) && (ny == y - 1 || ny == y + 1))
			x = nx, y = ny;
		else
			check = 1;
	}
	if (check)
		cout << "Invalid";
	else
		cout << "Valid";
	return 0;
}