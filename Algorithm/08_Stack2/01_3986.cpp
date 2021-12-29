#include <bits/stdc++.h>
using namespace std;

stack<char> s;
int n, cnt;
string str;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        while (!s.empty()) s.pop();
        cin >> str;
        for (int i = 0; str[i] != '\0'; i++) {
            if (s.empty() || s.top() != str[i])
                s.push(str[i]);
            else if (s.top() == str[i])
                s.pop();
        }
        if (s.empty())
            cnt++;
    }
    cout << cnt;
}