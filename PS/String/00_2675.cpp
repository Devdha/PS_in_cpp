#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, it;
    string str;
    cin >> n;
    while (n--) {
        cin >> it;
        cin >> str;
        for (int i = 0; str[i] != '\0'; i++) {
            for (int j = 0; j < it; j++)
                cout << str[i];
        }
        cout << '\n';
    }
}