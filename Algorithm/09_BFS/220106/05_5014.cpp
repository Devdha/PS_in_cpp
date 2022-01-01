#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
queue<int> q;
int fl[1000001];

int BFS() {
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) return fl[cur];
        for (int i = 0; i < 2; i++) {
            int n;
            if (i % 2 == 0) n = cur + u;
            else n = cur - d;
            if (n < 1 || n > f) continue;
            if (fl[n] != -1) continue;
            fl[n] = fl[cur] + 1;
            q.push(n);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    fill(fl, fl + (f + 1), -1);
    q.push(s);
    fl[s] = 0;
    int res = BFS();
    if (res == -1) cout << "use the stairs";
    else cout << res;
}