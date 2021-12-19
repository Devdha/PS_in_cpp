#include <bits/stdc++.h>
using namespace std;

int n, c;
long long tot;
stack<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        tot += (long long) s.size();
        cout << tot << '\n';
        while (!s.empty()) {
            if (c <= s.top())
                break;
            s.pop();
        }
        s.push(c);
    }
    cout << tot;
}