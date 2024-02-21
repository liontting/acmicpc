#include <iostream>
#include <queue>
using namespace std;
int v, h, board[110][110], visited[110][110], t, num;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> h;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < h; j++)
            cin >> board[i][j];
    while (1) {
        int check = 0;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < h; j++)
                visited[i][j] = 0;
        q.push({ 0,0 });
        visited[0][0] = 1;
        while (!q.empty()) {
            int qx = q.front().first, qy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = qx + dx[i], y = qy + dy[i];
                if (x >= 0 && x < v && y >= 0 && y < h && !visited[x][y]) {
                    visited[x][y] = 1;
                    if (!board[x][y])
                        q.push({ x,y });
                    else {
                        check++;
                        board[x][y] = 0;
                    }
                }
            }
        }
        if (!check)
            break;
        num = check;
        t++;
    }
    cout << t << "\n" << num;
    return 0;
}