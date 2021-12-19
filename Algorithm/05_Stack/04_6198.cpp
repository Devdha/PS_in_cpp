#include <bits/stdc++.h>
using namespace std;

long long tot;
int n, c;
stack<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        while (!s.empty()) {
            if (s.top() > c)
                break;
            s.pop();
        }
        tot += (long long)s.size();
        s.push(c);
    }
    cout << tot;
}