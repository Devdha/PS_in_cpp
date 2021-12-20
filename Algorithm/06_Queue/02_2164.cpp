#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n, res;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);
    for (int i = 1; !q.empty(); i++) {
        if (i % 2 == 1) {
            res = q.front();
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    cout << res;
}