#include <iostream>

using namespace std;

int dp[31];

int main() {
    int n;
    cin >> n;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= n; i += 2) {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }
    cout << dp[n];
}

// https://jaehoon0124welcome.tistory.com/36