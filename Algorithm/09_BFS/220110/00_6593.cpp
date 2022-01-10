#include <bits/stdc++.h>
using namespace std;

int x, y, z, res;
queue<tuple<int, int, int> > q;
char board[31][31][31];
int vis[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int BFS() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (!q.empty()) {
        int cz = get<0>(q.front());
        int cy = get<1>(q.front());
        int cx = get<2>(q.front());
        q.pop();
        if (board[cz][cy][cx] == 'E') 
            return vis[cz][cy][cx] - 1;
        for (int i = 0; i < 6; i++) {
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nz < 0 || ny < 0 || nx < 0) continue;
            if (nz >= z || ny >= y || nx >= x) continue;
            if (board[nz][ny][nx] == '#' || vis[nz][ny][nx]) continue;
            q.push({nz, ny, nx});
            vis[nz][ny][nx] = vis[cz][cy][cx] + 1;
        }
    }
    return -1;
}

int main() {
    cin >> z >> y >> x;
    while (x != 0) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < y; j++) {
                fill(vis[i][j], vis[i][j] + x, 0);
                for (int k = 0; k < x; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        q.push({i, j, k});
                        vis[i][j][k] = 1;
                    }
                }
            }
        }
        res = BFS();
        if (res == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << res << " minute(s).\n";
        cin >> z >> y >> x;
    }
}
