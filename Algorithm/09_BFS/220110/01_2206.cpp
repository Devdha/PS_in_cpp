#include <bits/stdc++.h>
using namespace std;

queue<tuple<int, int, int> > q;
string b[1001];
int vis[1001][1001][2];
int y, x, fin = 1;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int BFS() {
    vis[0][0][0] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        int qy, qx, wall;
        tie(qy, qx, wall) = q.front(); q.pop();
        if (qy == y - 1 && qx == x - 1) return vis[qy][qx][wall];
        for (int i = 0; i < 4; i++) {
            int ny = qy + dy[i];
            int nx = qx + dx[i];
            if (ny < 0 || nx < 0 || ny >= y || nx >= x) continue;
            if (b[ny][nx] == '0' && vis[ny][nx][wall] == 0) {
                vis[ny][nx][wall] = vis[qy][qx][wall] + 1;
                q.push({ny, nx, wall});
            }
            if (wall == 0 && b[ny][nx] == '1' && vis[ny][nx][1] == 0) {
                vis[ny][nx][1] = vis[qy][qx][wall] + 1;
                q.push({ny, nx, 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> y >> x;
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    cout << BFS();
}