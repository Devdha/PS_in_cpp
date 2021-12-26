#include <bits/stdc++.h>
using namespace std;

string WB = "WBWBWBWB";
string BW = "BWBWBWBW";

int check_to_paint(string line, bool wb) {
    int cnt = 0;
    if (wb) {
        for (int i = 0; i < 8; i++) {
            if ((i % 2 == 0 && line[i] != 'W') || (i % 2 == 1 && line[i] != 'B'))
                cnt++;
        }
    } else {
        for (int i = 0; i < 8; i++) {
            if ((i % 2 == 0 && line[i] != 'B') || (i % 2 == 1 && line[i] != 'W'))
                cnt++;
        }
    }
    return cnt;
}

int main() {
    
}