#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;
int sz, cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            s.push('(');
            sz++;
        } else if (str[i] == ')' && str[i - 1] == '(') {
            s.pop();
            sz--;
            cnt += sz;
        } else {
            s.pop();
            sz--;
            cnt++;
        }
    }
    cout << cnt;
}