#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, x, y;
vector<pair<int, int> > v;

bool com(pair<int, int> a, pair<int, int> b) {
    if (a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), com);
    for (auto i: v) cout << i.X << ' ' << i.Y << '\n';
}