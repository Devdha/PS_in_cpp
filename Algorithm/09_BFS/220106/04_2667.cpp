#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n;
vector<int> v;
string board[25];
queue<pair<int, int> > q;
bool vis[25][25];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int BFS() {
    int size = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[ny][nx] != '1' || vis[ny][nx]) continue;
            vis[ny][nx] = 1;
            q.push({ny, nx});
            size++;
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0 && board[i][j] == '1') {
                q.push({i, j});
                vis[i][j] = 1;
                v.push_back(BFS());
            }
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto i: v) {
        cout << i << '\n';
    }
}