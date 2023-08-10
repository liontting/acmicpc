#include <iostream>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int i = 1;
	while (i*i <= N) {
		i++;
		if (i*i == N)
			break;
		else if (i*i > N) {
			i--;
			break;
		}
	}
	cout << i;
	return 0;
}