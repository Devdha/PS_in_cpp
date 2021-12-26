#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;
int b[16], tot, cur, curr;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
            curr++;
        } else if (str[i] == ')' || ']') {
            cur = str[i] == ')' ? 2 : 3;
            if (s.empty() || s.top() != str[i] - (cur - 1)) {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == str[i] - (cur - 1)) {
                b[curr] += cur;
            } else {
                b[curr] += cur * b[curr + 1];
                b[curr + 1] = 0;
            }
            curr--;
            s.pop();
        }
        if (curr == 0) {
            tot += b[1];
            fill(b, b + 16, 0);
        }
    }
    cout << tot;
}