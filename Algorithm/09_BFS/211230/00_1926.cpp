#include <bits/stdc++.h>
using namespace std;
#define X first

#define Y second
int n, m, cnt, mx;
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] && vis[i][j] != 1) {
                queue<pair<int, int> > q;
                vis[i][j] = 1;
                q.push({i, j});
                int size = 1;
                while (!q.empty()) {
                    pair<int , int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        size++;
                    }
                }
                mx = mx > size ? mx : size;
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << mx;
}