#include <bits/stdc++.h>
using namespace std;

int M, N, B, W, res = 64;
string b[51];
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int chess(int y, int x) {
    B = 0;
    W = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int ny = y + i;
            int nx = x + j;
            if (b[ny][nx] != WB[i][j])
                W++;
            if (b[ny][nx] != BW[i][j])
                B++;
        }
    }
    return min(B, W);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    for (int i = 0; i + 7 < M; i++) {
        for (int j = 0; j + 7 < N; j++) {
            res = min(res, chess(i, j));
        }
    }
    cout << res;
}