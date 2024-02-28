#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N, area[15], n, a, visited[15], group[15], answer = -1;
vector<int> adj[15];

void check(int x) {
    visited[x] = 1;
    for (int i = 0; i < adj[x].size(); i++)
        if (!visited[adj[x][i]] && group[x] == group[adj[x][i]])
            check(adj[x][i]);
}

void solve(int num) {
    if (num == N + 1) {
        for (int i = 1; i <= N; i++)
            visited[i] = 0;
        int check_a = 0, check_b = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                if (group[i] && !check_a)
                    check_a = 1;
                else if (!group[i] && !check_b)
                    check_b = 1;
                else
                    return;
                check(i);
            }
        }
        int cnt_a = 0, cnt_b = 0;
        for (int i = 1; i <= N; i++) {
            if (group[i])
                cnt_a += area[i];
            else
                cnt_b += area[i];
        }
        if (cnt_a && cnt_b)
            if (answer == -1 || answer > abs(cnt_a - cnt_b))
                answer = abs(cnt_a - cnt_b);
        return;
    }
    group[num] = 1;
    solve(num + 1);
    group[num] = 0;
    solve(num + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> area[i];
    for (int i = 1; i <= N; i++) {
        cin >> n;
        while (n--) {
            cin >> a;
            adj[i].push_back(a);
        }
    }
    solve(1);
    cout << answer;
	return 0;
}