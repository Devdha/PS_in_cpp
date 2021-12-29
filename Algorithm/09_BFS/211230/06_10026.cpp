#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, cnt, weak_cnt;
char c;
string b[101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

void BFS() {
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (b[nx][ny] != c || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void roll() {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                c = b[i][j];
                cnt++;
                q.push({i, j});
                vis[i][j] = true;
                BFS();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    roll();
    cout << cnt << ' ';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] == 'G')
                b[i][j] = 'R';
        }
    }
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);
    c = 0;
    cnt = 0;
    roll();
    cout << cnt;
}
