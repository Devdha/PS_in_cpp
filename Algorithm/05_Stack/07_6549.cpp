#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, h[100010];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        cin >> n;
        if (n == 0)
            return (0);
        for (int i = 0; i < n; i++) cin >> h[i];
        h[n] = -1;
        stack<int> st;
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                int pos = st.top();
                st.pop();
                int len = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, h[pos] * len);
            }
            st.push(i);
        }
        cout << ans << '\n';
    }
}
