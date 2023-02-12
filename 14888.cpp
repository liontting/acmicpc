#include <iostream>
using namespace std;
int N, A[15], oper[5];
long long int minnum = 1000000000, maxnum = -1000000000;

void bt(int num, int idx, int ad, int su, int mu, int di) {
    if (idx == N) {
        if (maxnum < num)
            maxnum = num;
        if (minnum > num)
            minnum = num;
        return;
    }
    if (ad > 0)
        bt(num + A[idx], idx + 1, ad - 1, su, mu, di);
    if (su > 0)
        bt(num - A[idx], idx + 1, ad, su - 1, mu, di);
    if (mu > 0)
        bt(num * A[idx], idx + 1, ad, su, mu - 1, di);
    if (di > 0)
        bt(num / A[idx], idx + 1, ad, su, mu, di - 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];
    bt(A[0], 1, oper[0], oper[1], oper[2], oper[3]);
    cout << maxnum << "\n" << minnum;
    return 0;
}