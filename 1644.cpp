#include <iostream>
#include <vector>
using namespace std;
int N, answer;
bool prime[4000010];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++)
		prime[i] = true;
	for (int i = 2; i * i <= N; i++)
		if (prime[i])
			for (int j = i * i; j <= N; j += i)
				prime[j] = false;
	for (int i = 2; i <= N; i++)
		if (prime[i])
			v.push_back(i);
	int s = 0, e = 0;
	while (e < (int)v.size()) {
		int sum = 0;
		for (int i = s; i <= e; i++)
			sum += v[i];
		if (sum < N)
			e++;
		else if (sum == N) {
			answer++;
			e++;
		}
		else
			s++;
	}
	cout << answer;
	return 0;
}