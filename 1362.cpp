#include <iostream>
using namespace std;
int o, w, n, scenario;
char m;

int main() {
	while (1) {
		int check = 0;
		scenario++;
		cin >> o >> w;
		if (!o && !w)
			break;
		while (1) {
			cin >> m >> n;
			if (m == 'E') {
				w -= n;
				if (w <= 0)
					check = 1;
			}
			else if (m == 'F')
				w += n;
			else
				break;
		}
		cout << scenario << " ";
		if (w <= 0 || check == 1)
			cout << "RIP\n";
		else if (w > o / 2 && w < 2 * o)
			cout << ":-)\n";
		else
			cout << ":-(\n";
	}
	return 0;
}