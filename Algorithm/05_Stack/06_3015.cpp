#include <bits/stdc++.h>
using namespace std;

int n, c, same_c;
long long tot;
stack<pair<int,int> > s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;

        same_c = 1;
        while (!s.empty() && s.top().first < c) {
            tot += s.top().second;
            s.pop();
        }
        if (!s.empty()) {
            if (s.top().first == c) {
                tot += s.top().second;
                same_c = (s.top().second + 1);
                if (s.size() > 1)
                    tot++;
                s.pop();
            } else {
                tot++;
            }
        }
        s.push(make_pair(c, same_c));
    }
    cout << tot;
}

    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cin >> c;
    //     tot += (long long) s.size();
    //     while (!s.empty()) {
    //         if (c <= s.top())
    //             break;
    //         s.pop();
    //     }
    //     s.push(c);
    // }
    // cout << tot;