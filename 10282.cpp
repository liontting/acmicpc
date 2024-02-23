#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
int T, n, d, c, a, b, s, computer[10010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
        vector<pair<int,int>> v[10010];
        priority_queue<pair<int, int>> pq;
        int time = 0, cnt = 0;
        cin >> n >> d >> c;
        for (int i = 1; i <= n; i++)
            computer[i] = 987654321;
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            v[b].push_back({ a,s });
        }
        computer[c] = 0;
        pq.push({ 0, c });
        while (!pq.empty()) {
            int c2 = pq.top().second, t = -pq.top().first;
            pq.pop();
            for (int i = 0; i < v[c2].size(); i++) {
                if (computer[v[c2][i].first] > t + v[c2][i].second) {
                    computer[v[c2][i].first] = t + v[c2][i].second;
                    pq.push({ -computer[v[c2][i].first],v[c2][i].first });
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (computer[i] != 987654321) {
                cnt++;
                time = max(time, computer[i]);
            }
        }
        cout << cnt << " " << time << "\n";
    }
	return 0;
}