#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n, maxtall, res;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;
int board[101][101];
bool v[101][101];

void BFS(int tall) {
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[ny][nx] <= tall || v[ny][nx]) continue;
            v[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            maxtall = max(maxtall, board[i][j]);
        }
    
    for (int i = 0; i < maxtall; i++) {
        for (int j = 0; j < 101; j++)
            fill(v[j], v[j] + 101, 0);
        
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (v[j][k] != 1 && board[j][k] > i) {
                    q.push({j, k});
                    v[j][k] = 1;
                    cnt++;
                    BFS(i);
                }
            }
        }
        res = max(res, cnt);
    }
}