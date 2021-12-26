#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;
int b[16], tot;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int curr = 0;
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
            curr++;
        } else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(') {
                b[curr] += 2;
                curr--;
            } else {
                b[curr] += 2 * b[curr + 1];
                b[curr + 1] = 0;
                curr--;
            }
            s.pop();
        } else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[') {
                b[curr] += 3;
                curr--;
            } else {
                b[curr] += 3 * b[curr + 1];
                b[curr + 1] = 0;
                curr--;
            }
            s.pop();
        }
        // cout << b[curr + 1] << '\n';
        if (curr == 0) {
            tot += b[1];
            fill(b, b + 16, 0);
        }
    }
    cout << tot;
}