#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first

int R, C;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string board[1001];
bool vis[1001][1001];
queue<pair<int, int> > q;
queue<pair<int, int> > fire;

int BFS() {
    int result = 0;
    while (!q.empty()) {
        int fsize = fire.size();
        for (int i = 0; i < fsize; i++) {
            pair<int, int> cur = fire.front(); fire.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
                if (board[ny][nx] == '.' || board[ny][nx] == 'J') {
                    board[ny][nx] = 'F';
                    fire.push({ny, nx});
                }
            }
        }
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.X == C - 1 || cur.X == 0 || cur.Y == R - 1 || cur.Y == 0)
                return result + 1;

            for (int j = 0; j < 4; j++) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
                if (!vis[ny][nx]) {
                    if (board[ny][nx] == '.') {
                        vis[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'J') {
                q.push({i, j});
                vis[i][j] = true;
            }
            else if (board[i][j] == 'F') fire.push({i, j});
        }
    }
    int result = BFS();
    if (result == -1) cout << "IMPOSSIBLE";
    else cout << result;
}


// int main() {
//     cin >> R >> C;
//     for (int i = 0; i < R; i++) {
//         for (int j = 0; j < C; j++) {
//             cin >> board[i][j];
//             if (board[i][j] == 'J') {
//                 if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
//                     cout << 0;
//                     return 0;
//                 }
//                 q.push({i, j});
//             }
//         }
//         for (int j = 0; j < C; j++) {
//             if (board[i][j] == 'F') q.push({i, j});
//         }
//     }
//     while (!q.empty()) {
//         pair<int, int> cur = q.front(); q.pop();
//         if (cur.Y == 0 || cur.Y == R - 1 || cur.X == 0 || cur.X == C - 1) {
//             if (board[cur.Y][cur.X] == 'J') {
//                 cout << 1;
//                 return 0;
//             } else if (board[cur.Y][cur.X] >= '0' && board[cur.Y][cur.X] <= '9') {
//                 cout << board[cur.Y][cur.X];
//                 return 0;
//             }
//         }
//         for (int i = 0; i < 4; i++) {
//             int nx = cur.X + dx[i];
//             int ny = cur.Y + dy[i];
//             if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
//             if (board[ny][nx] != '.') continue;
//             if (board[cur.Y][cur.X] == 'J') {
//                 board[ny][nx] = '2';
//                 q.push({ny, nx});
//             }else if (board[cur.Y][cur.X] >= '0' && board[cur.Y][cur.X] <= '9') {
//                 board[ny][nx] = board[cur.Y][cur.X] + 1;
//             } else {
//                 board[ny][nx] = 'F';
//                 q.push({ny, nx});
//             }
//         }
//     }
//     cout << "IMPOSSIBLE";
//     return 0;
// }