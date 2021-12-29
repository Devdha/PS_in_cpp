#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int vis[100001];
int N, K;

int main() {
    cin >> N >> K;
    fill(vis, vis + 100001, -1);
    q.push(N);
    vis[N] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == K) {
            cout << vis[cur];
            return 0;
        }
        for (int nxt : {cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (vis[nxt] != -1) continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
}