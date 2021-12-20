#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0, c;
    for (int i = 0; i < 5; i++) {
        cin >> c;
        sum += (c * c);
    }
    cout << (sum % 10);
}