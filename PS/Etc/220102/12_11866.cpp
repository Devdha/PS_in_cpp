#include <bits/stdc++.h>
using namespace std;

int n, c, cnt = 1;
queue<int> q;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    cin >> c;
    while (!q.empty()) {
        if (cnt % c == 0) {
            v.push_back(q.front());
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    cout << '<';
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i];
        if (i != size - 1) cout << ", ";
    }
    cout << '>';
}