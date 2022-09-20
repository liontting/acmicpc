# acmicpc
Baekjoon Online Judge

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
