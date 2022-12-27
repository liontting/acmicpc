#include <iostream>
using namespace std;
int N, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N) {
		int n;
		for (int i = 0; i < N; i++)
			cin >> n;
		c++;
		cout << "Case " << c << ": Sorting... done!\n";
		cin >> N;
	}
}