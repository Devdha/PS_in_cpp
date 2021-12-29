#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int vis[101][101];
string board[101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    vis[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != '1') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    cout << vis[n - 1][m - 1];
}