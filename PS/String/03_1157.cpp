#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int c[26] = {0,};
    string str;
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            c[str[i] - 'A']++;
        else
            c[str[i] - 'a']++;
    }
    int max = 0;
    for (int i = 1; i < 26; i++)
        max = c[max] > c[i] ? max : i;
    for (int i = 0; i < 26; i++)
        if (c[max] == c[i] && i != max) {
            cout << '?';
            return 0;
        }
    cout << (char)(max + 'A');
}