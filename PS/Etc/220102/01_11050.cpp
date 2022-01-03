#include <bits/stdc++.h>
using namespace std;

int factorial(int i) {
    if (i == 0) return 1;
    
    int result = 1;
    for (int j = i; j >= 1; j--)
        result *= j;
    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(k) * factorial(n - k));
}