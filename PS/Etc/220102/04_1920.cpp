#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int n, m, c;

int f(int a) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == a)
            return 1;
        else if (A[mid] < a)
            start = mid + 1;
        else if (A[mid] > a)
            end = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        A.push_back(c);
    }
    sort(A.begin(), A.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        cout << f(c) << '\n';
    }
}