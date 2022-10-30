#include <iostream>
#include <string>
using namespace std;
int N, cnt;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> S;
	for (int i = 0; i < N; i++)
		if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
			cnt++;
	cout << cnt;
	return 0;
}