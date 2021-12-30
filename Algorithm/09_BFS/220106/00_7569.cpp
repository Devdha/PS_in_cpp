#include <bits/stdc++.h>
using namespace std;

int x, y, z, ret;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[101][101][101];
queue<tuple<int, int, int> > q;

void BFS() {
    while (!q.empty()) {
        tuple<int, int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = get<2>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<0>(cur) + dz[i];
            if (nx < 0 || ny < 0 || nz < 0) continue;
            if (nx >= x || ny >= y || nz >= z) continue;
            if (board[nz][ny][nx] == 0) {
                board[nz][ny][nx] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                q.push({nz, ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y >> z;
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    BFS();
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                if (board[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                if (board[i][j][k] > ret) ret = board[i][j][k];
            }
        }
    }
    cout << ret - 1;
}