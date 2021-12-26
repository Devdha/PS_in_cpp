#include <bits/stdc++.h>
using namespace std;

stack<char> s;
int n;
string str;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        while (!s.empty()) s.pop();
        cin >> str;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == ')') {
                if (s.empty()) {
                    s.push(str[i]);
                    break;
                }
                s.pop();
            }
        }
        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}