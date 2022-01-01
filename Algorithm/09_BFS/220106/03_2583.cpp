#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n, m, t, x, y, des_x, des_y, cnt;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int board[101][101];
bool vis[101][101];
queue<pair<int, int> > q;
vector<int> v;

int BFS() {
    int size = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (board[ny][nx] || vis[ny][nx]) continue;
            size++;
            vis[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> des_x >> des_y;
        for (int j = y; j < des_y; j++)
            for (int k = x; k < des_x; k++)
                board[j][k] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 && vis[i][j] == 0) {
                cnt++;
                q.push({i, j});
                vis[i][j] = 1;
                v.push_back(BFS());
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (auto i: v) {
        cout << i << ' ';
    }
}