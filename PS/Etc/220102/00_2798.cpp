#include <bits/stdc++.h>
using namespace std;

int n, b, res;
int c[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if (c[i] + c[j] + c[k] > b) continue;
                res = max(res, c[i] + c[j] + c[k]);
            }
        }
    }
    cout << res;
}