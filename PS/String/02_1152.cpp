#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int check = 0,n = 0;
    string str;
    getline(cin, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && check == 0) {
            check = 1;
            n++;
        } else if (str[i] == ' ' && check == 1) {
            check = 0;
        }
    }
    cout << n;
}