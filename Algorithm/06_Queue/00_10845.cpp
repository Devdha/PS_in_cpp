#include <bits/stdc++.h>
using namespace std;

queue<int> q;
string com;
int n, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0)
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com;
        if (strcmp(com.c_str(), "push") == 0) {
            cin >> c;
            q.push(c);
        } else if (strcmp(com.c_str(), "pop") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (strcmp(com.c_str(), "size") == 0) {
            cout << q.size() << '\n';
        } else if (strcmp(com.c_str(), "empty") == 0) {
            cout << q.empty() << '\n';
        } else if (strcmp(com.c_str(), "front") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        } else if (strcmp(com.c_str(), "back") == 0) {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }
}