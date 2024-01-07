#include <iostream>
using namespace std;
int N, A[1000010], B, C;
long long int num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	num = N;
	for (int i = 0; i < N; i++) {
		if (A[i] - B > 0) {
			num += (A[i] - B) / C;
			if ((A[i] - B) % C != 0)
				num++;
		}
	}
	cout << num;
	return 0;
}