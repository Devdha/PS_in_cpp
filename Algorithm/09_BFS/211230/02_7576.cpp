#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n, m, result, board[1001][1001];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > ripe;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) ripe.push({i, j});
        }
    }
    while (!ripe.empty()) {
        pair<int, int> cur = ripe.front(); ripe.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[ny][nx] == 0) {
                board[ny][nx] = board[cur.Y][cur.X] + 1;
                ripe.push({ny, nx});
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            result = result > board[i][j] ? result : board[i][j];
        }
    }
    cout << result - 1;
}

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> board[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (board[i][j] == 1) {
//                 queue<pair<int, int> > q;
//                 q.push({i, j});
//                 while (!q.empty()) {
//                     pair<int, int> cur = q.front(); q.pop();
//                     for (int dir = 0; dir < 4; dir++) {
//                         int nx = cur.X + dx[dir];
//                         int ny = cur.Y + dy[dir];
//                         if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//                         if (board[nx][ny] == -1 || board[nx][ny] == 1) continue;
//                         if (day[nx][ny] != 0 && day[nx][ny] < day[cur.X][cur.Y] + 1) continue;
//                         day[nx][ny] = day[cur.X][cur.Y] + 1;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         }
//     }
//     int ret = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (board[i][j] == 0 && day[i][j] == 0) {
//                 cout << -1;
//                 return 0;
//             }
//             if (day[i][j] > ret) ret = day[i][j];
//         }
//     }
//     cout << ret;
// }