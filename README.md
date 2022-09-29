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

### Depth First Search
(2638)

``` c++
void dfs(int x) {
	visited[x] = 1;
	for (int i: graph[x])
		if (!visited[i] && ... )
			dfs(i);
}

```

### Dijkstra
(14938, 11779)

``` c++
void dijkstra() {
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> e;
		graph[a].push_back(make_pair(b, e));
	}
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	priority_queue<pair <int, int> > pq;
	dist[1] = 0; // 1번부터 각 노드
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();
		if (nowdist > dist[now]) // 의미 없는 경우 제거하여 최적화
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			pair<int, int> next = graph[now][i];
			if (dist[next.first] > nowdist + next.second) {
				dist[next.first] = nowdist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
}
```

### Tree traversal

preorder: root -> left -> right
``` c++
void pre(root* temp) {
	if (temp) {
		cout << temp->data;
		pre(temp->left);
		pre(temp->right);
	}
}
```

inorder: left -> root -> right
``` c++
void in(root* temp) {
	if (temp) {
		in(temp->left);
		cout << temp->data;
		in(temp->right);
	}
}
```

postorder: left -> right -> root
``` c++
void post(root* temp) {
	if (temp) {
		post(temp->left);
		post(temp->right);
		cout << temp->data;
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
