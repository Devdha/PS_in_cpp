#include <bits/stdc++.h>
using namespace std;;

vector<tuple<int, int, string> > v;
int n, age;
string name;

bool compare(tuple<int, int, string> a, tuple<int, int, string> b) {
    if (get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        v.push_back({i, age, name});
    }
    sort(v.begin(), v.end(), compare);
    for (auto i: v) {
        cout << get<1>(i) << ' ' << get<2>(i) << '\n';
    }
}