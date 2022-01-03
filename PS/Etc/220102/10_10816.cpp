#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int b[500001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        auto upper = upper_bound(b, b + n, c);
        auto lower = lower_bound(b, b + n, c);
        cout << upper - lower << ' ';
    }
}