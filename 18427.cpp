#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int N, M, H, dp[60][1010];
vector<int> h[60];
string s, word;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> H;
    getline(cin, s);
    for (int i = 1; i <= N; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> word)
            h[i].push_back(stoi(word));
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= H; j++) {
            dp[i][j] += dp[i - 1][j] % 10007;
            for (int k = 0; k < (int)h[i].size(); k++)
                if (j + h[i][k] <= H)
                    dp[i][j + h[i][k]] += dp[i - 1][j] % 10007;
        }
    }
    cout << dp[N][H] % 10007;
	return 0;
}