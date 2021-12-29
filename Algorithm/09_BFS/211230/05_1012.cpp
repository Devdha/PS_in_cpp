#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, cnt, n, m, num;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cnt = 0;
        int board[51][51] = {0,};
        bool vis[51][51] = {0,};
        cin >> n >> m >> num;
        int x, y;
        for (int i = 0; i < num; i++) {
            cin >> x >> y;
            board[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] && vis[i][j] != 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                    cnt++;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front(); q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (board[nx][ny] != 1 || vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}