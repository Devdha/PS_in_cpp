#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
    int n, c;
    string cmd;
    cin >> n;
    while (n--) {
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> c;
            dq.push_front(c);
        } else if (cmd == "push_back") {
            cin >> c;
            dq.push_back(c);
        } else if (cmd == "pop_front") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (cmd == "size") {
            if (dq.empty()) cout << 0 << '\n';
            else cout << dq.size() << '\n';
        } else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        } else if (cmd == "front") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        } else if (cmd == "back") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}