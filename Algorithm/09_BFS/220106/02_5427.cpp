#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y first

int t, R, C;
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
                if (board[ny][nx] == '.' || board[ny][nx] == '@') {
                    board[ny][nx] = '*';
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
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1001; i++)
            fill(vis[i], vis[i] + 1001, 0);
        while (!q.empty()) q.pop();
        while (!fire.empty()) fire.pop();
        cin >> C >> R;
        for (int i = 0; i < R; i++) {
            cin >> board[i];
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '@') {
                    q.push({i, j});
                    vis[i][j] = true;
                }
                else if (board[i][j] == '*') fire.push({i, j});
            }
        }
        int result = BFS();
        if (result == -1) cout << "IMPOSSIBLE" << '\n';
        else cout << result << '\n';
    }
}