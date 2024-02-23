#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
int N, task[10010], indegree[10010], n, t, answer;
vector<int> v[10010];
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> task[i] >> n;
        for (int j = 0; j < n; j++){
            cin >> t;
            v[t].push_back(i);
            indegree[i]++;
        }
        if (!n)
            pq.push({ -task[i],i });
    }
    while (!pq.empty()) {
        int cur = pq.top().second;
        t = -pq.top().first;
        answer = max(answer, t);
        pq.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            indegree[next]--;
            if (!indegree[next])
                pq.push({ -(task[next] + t), next });
        }
    }
    cout << answer;
	return 0;
}