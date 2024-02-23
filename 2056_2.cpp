#include <iostream>
#include <math.h>
using namespace std;
int N, task[10010], n, t, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> task[i] >> n;
        int prev = 0;
        for (int j = 0; j < n; j++){
            cin >> t;
            prev = max(prev, task[t]);
        }
        task[i] += prev;
        answer = max(answer, task[i]);
    }
    cout << answer;
	return 0;
}