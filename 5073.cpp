#include <iostream>
#include <algorithm>
using namespace std;
int x[5];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for (int i = 0; i < 3; i++)
		cin >> x[i];
	while (x[0] || x[1] || x[2]) {
		sort(x, x + 3);
		if (x[0] == x[1] && x[0] == x[2])
			cout << "Equilateral\n";
		else {
			if (x[2] >= x[0] + x[1])
				cout << "Invalid\n";
			else if(x[0] == x[1] || x[1] == x[2])
				cout << "Isosceles\n";
			else
				cout << "Scalene\n";
		}
		for (int i = 0; i < 3; i++)
			cin >> x[i];
	}
	return 0;
}