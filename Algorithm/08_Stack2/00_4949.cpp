#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (1) {
        while (!s.empty()) s.pop();
        getline(cin, str);
        if (str[0] == '.' && str[1] == '\0')
            return 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else if (str[i] == ')' || str[i] == ']') {
                if (s.empty() || s.top() != (str[i] == ')' ? '(' : '[')) {
                    cout << "no\n";
                    break;
                }
                s.pop();
            }
            if (str[i + 1] == '\0' && s.empty()) {
                cout << "yes\n";
            } else if (str[i + 1] == '\0')
                cout << "no\n";
        }
    }
}