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
