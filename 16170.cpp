#include <iostream>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	time_t timer = time(NULL);
	struct tm* t = gmtime(&timer);
	cout << t->tm_year + 1900 << "\n" << t->tm_mon + 1 << "\n" << t->tm_mday;
	return 0;
}