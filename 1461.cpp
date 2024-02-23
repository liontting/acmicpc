#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, book, answer, pi, ni;
vector<int> pos, neg;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> book;
        if (book > 0)
            pos.push_back(book);
        else
            neg.push_back(book);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());
    if (!neg.size() || (pos.size() && pos[0] > -neg[0])) {
        answer += pos[0];
        pi += M;
    }
    else {
        answer -= neg[0];
        ni += M;
    }
    while (pi < pos.size()) {
        answer += 2*pos[pi];
        pi += M;
    }
    while (ni < neg.size()) {
        answer -= 2*neg[ni];
        ni += M;
    }
    cout << answer;
	return 0;
}