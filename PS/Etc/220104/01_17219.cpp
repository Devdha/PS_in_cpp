#include <bits/stdc++.h>
using namespace std;

int x, y;
string a, b;
map<string, string> m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        cin >> a >> b;
        m.insert({a, b});
    }
    for (int i = 0; i < y; i++) {
        cin >> a;
        cout << m[b] << '\n';
    }
}