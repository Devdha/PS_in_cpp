#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> arr(n), ans(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}