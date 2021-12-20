#include <bits/stdc++.h>
using namespace std;

string r, l;
int rr, ll;

int main() {
    cin >> r >> l;
    reverse(r.begin(), r.end());
    reverse(l.begin(), l.end());
    rr = stoi(r);
    ll = stoi(l);
    cout << (rr > ll ? rr : ll);
}