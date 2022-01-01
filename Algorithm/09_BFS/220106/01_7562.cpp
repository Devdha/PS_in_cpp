#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n, x, y;
int board[301][301];
queue<pair<int, int> > q;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int BFS() {
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (cur.X == x && cur.Y == y) return board[cur.X][cur.Y];
        for (int i = 0; i < 8; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] != -1) continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < 301; i++)
            fill(board[i], board[i] + 300, -1);
        cin >> n;
        cin >> x >> y;
        q.push({x, y});
        board[x][y] = 0;
        cin >> x >> y;
        cout << BFS() << '\n';
    }
}