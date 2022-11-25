#include <iostream>
#include <math.h>
using namespace std;
int maxnum;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int one, two, three, four, money = 0;
		cin >> one >> two >> three >> four;
		if (one == two && two == three && three == four)
			money = 50000 + one * 5000;
		else if (one == two && two == three)
			money = 10000 + one * 1000;
		else if (one == two && two == four)
			money = 10000 + one * 1000;
		else if (one == three && three == four)
			money = 10000 + one * 1000;
		else if (two == three && three == four)
			money = 10000 + two * 1000;
		else if (one == two) {
			if (three == four)
				money = 2000 + one * 500 + three * 500;
			else
				money = 1000 + one * 100;
		}
		else if (one == three) {
			if (two == four)
				money = 2000 + one * 500 + two * 500;
			else
				money = 1000 + one * 100;
		}
		else if (one == four) {
			if (three == two)
				money = 2000 + one * 500 + three * 500;
			else
				money = 1000 + one * 100;
		}
		else if (three == two)
			money = 1000 + three * 100;
		else if (four == two)
			money = 1000 + two * 100;
		else if (three == four)
			money = 1000 + three * 100;
		else {
			if (one > two && one > three && one > four)
				money = one * 100;
			else if (one < two && two > three && two > four)
				money = two * 100;
			else if (three > two && one < three && three > four)
				money = three * 100;
			else
				money = four * 100;
		}
		maxnum = max(maxnum, money);
	}
	cout << maxnum;
	return 0;
}
