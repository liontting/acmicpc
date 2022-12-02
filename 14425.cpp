#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, M, answer;
string S[10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	sort(S, S + N);
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (binary_search(S, S + N, s))
			answer++;
	}
	cout << answer;
}