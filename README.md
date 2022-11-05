# acmicpc
Baekjoon Online Judge

### Binary Search
(2467, 2110)

``` c++
int binary_search(int* arr, int target) {
	int left = 0, right = len - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
```

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
(2638, 1987)

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

### Minimum Spanning Tree (MST)
##### Kruskal's Algorithm
(1647, 4386, 2887, 6497, 14621, 1774, 16398, 10423)

``` c++
int find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = find(root[x]);
}

void uni(int x, int y) {
	if (find(x) != find(y))
		root[find(x)] = find(y);
}
// Union-Find (Disjoint Set) 그대로 사용

void kruskal() {
	for (int i = 0; i < N; i++)
		root[i] = i;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push(make_pair(-C, make_pair(A, B)));
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	while (!pq.empty()) {
		int c = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (find(a) != find(b)) {
			uni(a, b);
			answer += c;
		}
		pq.pop();
	}
}
```

### Topological Sort
(1005, 2252, 2623)

``` c++
void topological_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			q.push(i);
	for (int i = 1; i <= N; i++) {
		int cur = q.front();
		q.pop();
		answer[i] = cur;
		for (int i = 0; i < (int)v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}
```

### KnapSack Problem
##### 0-1 KnapSack Problem
(7579)

``` c++
void knapsack() {
	for (int i = 1; i <= N; i++)
		cin >> W[i];
	for (int i = 1; i <= N; i++)
		cin >> V[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= W[i])
				DP[i % 2][j] = max(DP[(i - 1) % 2][j], DP[(i - 1) % 2][j - W[i]] + V[i]);
			else
				DP[i % 2][j] = DP[(i - 1) % 2][j];
		}
	}
}
```

### Tree traversal

preorder: root -> left -> right
``` c++
void preorder(root* temp) {
	if (temp) {
		cout << temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}
}
```

inorder: left -> root -> right
``` c++
void inorder(root* temp) {
	if (temp) {
		inorder(temp->left);
		cout << temp->data;
		inorder(temp->right);
	}
}
```

postorder: left -> right -> root
``` c++
void postorder(root* temp) {
	if (temp) {
		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data;
	}
}
```

### Modular inverse
##### Fermat's little Theorem
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
// inverse(A, N - 2);
// A의 (N - 1)승을 N으로 나눈 나머지는 1 -> A의 (N - 2)승을 N으로 나눈 나머지는 1/A
```

### Fibonacci numbers
##### d'Ocagne's identity
F(m + n) = F(m - 1) * F(n) + F(m) * F(n + 1)  
(11444, 15624)

``` c++
long long int fibonacci(long long int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return (mem[1] = 1);
	else if (num == 2)
		return (mem[2] = 1);
	else if (mem[num])
		return mem[num];
	else {
		if (num % 2 == 0) {
			long long int a = fibonacci(num / 2 - 1);
			long long int b = fibonacci(num / 2);
			mem[num] = (a * b) + (b * (a + b));
			return mem[num];
		}
		else {
			long long int a = fibonacci(num / 2);
			long long int b = fibonacci(num / 2 + 1);
			mem[num] = (a * a) + (b * b);
			return mem[num];
		}
	}
}
```

### Palindrome
(10942)

``` c++
int palindrome(int s, int e) { // s부터 e의 값이 palindrome인지 dp로 풀이
	if (s > e)
		return 1;
	if (dp[s][e] != -1)
		return dp[s][e];
	if (num[s] != num[e])
		return dp[s][e] = 0;
	return dp[s + 1][e - 1] = palindrome(s + 1, e - 1);
}
```

### Shoelace formula
(2166)

``` c++
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	x[N] = x[0];
	y[N] = y[0];
	for (int i = 0; i < N; i++)
		answer += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
	answer = abs(answer) / 2; // answer, x, y의 type은 double
```

### Sieve of Eratosthenes
(1644)

``` c++
void eratosthenes() {
	for (int i = 2; i <= N; i++)
		prime[i] = true;
	for (int i = 2; i * i <= N; i++)
		if (prime[i])
			for (int j = i * i; j <= N; j += i)
				prime[j] = false;
}
```
