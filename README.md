# acmicpc
Baekjoon Online Judge

### Breadth First Search
``` c++
void bfs(int start) {
  queue <int> q;
  visited[start] = 1;
  q.push(start);
  
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (!visited[?] && ... ) {
      visited[?] = 1;
      q.push(?);
    }
  }
}
```

### Dijkstra
(14938)

``` c++
for (int i = 1; i <= N; i++)
  dist[i] = INF;
priority_queue<pair <int, int> > pq;
dist[1] = 0; // 1번부터 각 노드
pq.push(make_pair(0, 1));
while (!pq.empty()) {
	int now = pq.top().second;
	int nowdist = -pq.top().first;
	pq.pop();
	for (int i = 0; i < graph[now].size(); i++) {
		pair<int, int> next = graph[now][i];
		if (dist[next.first] >= nowdist + next.second) {
			dist[next.first] = nowdist + next.second;
			pq.push(make_pair(-dist[next.first], next.first));
		}
	}
}
```

### modular inverse
Fermat's little Theorem
(13172, 11401)

``` c++
long long inverse(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n % 2)
      r = (r * a) % X;
    a = (a * a) % X;
    n /= 2;
  }
  return r;
}
```
