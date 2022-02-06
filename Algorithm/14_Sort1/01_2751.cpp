#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n, c;
    cin >> n;
    while (n--) {
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (auto i: v) cout << i << '\n';
}