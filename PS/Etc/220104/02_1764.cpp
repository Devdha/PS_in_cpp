#include <bits/stdc++.h>
using namespace std;

vector<string> n, v;
int x, y;
string c;

int f() {
    int start = 0;
    int end = x - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (n[mid] == c)
            return 1;
        else if (n[mid] < c)
            start = mid + 1;
        else if (n[mid] > c)
            end = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        cin >> c;
        n.push_back(c);
    }
    sort(n.begin(), n.end());
    for (int i = 0; i < y; i++) {
        cin >> c;
        if(f()) v.push_back(c);
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto i: v) cout << i << '\n';
}