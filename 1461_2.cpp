#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N, M, book, answer;
vector<int> pos, neg;

void fun(vector<int> &v) {
    for (int i = v.size() - 1; i >= 0; i -= M)
        answer += 2 * v[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> book;
        answer = -max(-answer, abs(book));
        if (book > 0)
            pos.push_back(book);
        else
            neg.push_back(-book);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    fun(pos);
    fun(neg);
    cout << answer;
	return 0;
}