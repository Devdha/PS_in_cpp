#include <bits/stdc++.h>
using namespace std;

int t, n, pre;
int f[41][2];

void fibonacci(int n) {
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i - 1][0] + f[i - 2][0];
        f[i][1] = f[i - 1][1] + f[i - 2][1];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    f[0][0] = 1;
    f[0][1] = 0;
    f[1][0] = 0;
    f[1][1] = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        if (pre >= n) {
            cout << f[n][0] << ' ' << f[n][1] << '\n';
            continue;
        }
        fibonacci(n);
        cout << f[n][0] << ' ' << f[n][1] << '\n';
        pre = n;
    }
}