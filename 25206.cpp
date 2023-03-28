#include <iostream>
#include <string.h>
using namespace std;
char s[60], grade[10];
double point, sum, pointsum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(6);
	for (int i = 0; i < 20; i++) {
		cin >> s;
		cin >> point;
		cin >> grade;
		pointsum += point;
		if (!strcmp(grade, "A+"))
			sum += point * 4.5;
		else if (!strcmp(grade, "A0"))
			sum += point * 4.0;
		else if (!strcmp(grade, "B+"))
			sum += point * 3.5;
		else if (!strcmp(grade, "B0"))
			sum += point * 3.0;
		else if (!strcmp(grade, "C+"))
			sum += point * 2.5;
		else if (!strcmp(grade, "C0"))
			sum += point * 2.0;
		else if (!strcmp(grade, "D+"))
			sum += point * 1.5;
		else if (!strcmp(grade, "D0"))
			sum += point * 1.0;
		else if (!strcmp(grade, "P"))
			pointsum -= point;
	}
	cout << sum / pointsum;
	return 0;
}