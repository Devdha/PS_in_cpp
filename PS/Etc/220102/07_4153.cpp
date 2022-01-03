#include <bits/stdc++.h>
using namespace std;

int x, y, z, m, f, s;

int main () {
    cin >> x >> y >> z;
    m = max(x, y);
    m = max(m, z);
    while (x != 0) {
        if (x == m) {
            f = y; s = z;
        } else if (y == m) {
            f = z; s = x;
        } else if (z == m) {
            f = x; s = y;
        }
        if (f * f + s * s == m * m)
            cout << "right\n";
        else
            cout << "wrong\n";
        cin >> x >> y >> z;
        m = max(x, y);
        m = max(m, z);
    }
}