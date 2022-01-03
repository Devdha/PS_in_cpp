#include <bits/stdc++.h>
using namespace std;

int n;
string str;

bool compare(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto i: v) {
        cout << i << '\n';
    }
}