#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
deque<int> tmp1;
deque<int> tmp2;
int res;

int main() {
    int n, m, c, t1, t2;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        t1 = 0;
        t2 = 0;
        tmp1 = dq;
        tmp2 = dq;
        cin >> c;
        while (tmp1.front() != c) {
            tmp1.push_back(tmp1.front());
            tmp1.pop_front();
            t1++;
        }
        while (tmp2[0] != c) {
            tmp2.push_front(tmp2.back());
            tmp2.pop_back();
            t2++;
        }
        if (t1 <= t2) {
            while (dq.front() != c) {
                dq.push_back(dq.front());
                dq.pop_front();
                res++;
            }
        } else {
            while (dq.front() != c) {
                dq.push_front(dq.back());
                dq.pop_back();
                res++;
            }
        }
        dq.pop_front();
    }
    cout << res;
}