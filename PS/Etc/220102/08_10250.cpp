#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int h, w, n, cnt = 0;
        cin >> h >> w >> n;
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                cnt++;
                if (cnt == n) {
                    if (i < 10) {
                        cout << j << '0' << i << '\n';
                    } else {
                        cout << j << i << '\n';
                    }
                    break;
                }
            }
        }
    }
}