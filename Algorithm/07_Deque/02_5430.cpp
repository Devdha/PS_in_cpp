#include <bits/stdc++.h>
using namespace std;

int n, len;
string cmd, numlist;

deque<int> num_split(string nums) {
    deque<int> v;
    int num = 0;
    for (int i = 0; nums[i] != '\0'; i++) {
        if (isdigit(nums[i])) {
            num = num * 10 + (nums[i] - '0');
        } else if (nums[i] != '[' && num != 0) {
            v.push_back(num);
            num = 0;
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        int cmdlen = cmd.length();
        cin >> len;
        cin >> numlist;
        bool rev = false;
        bool err = false;
        deque<int> nums = num_split(numlist);
        for (int j = 0; j < cmdlen; j++) {
            if (cmd[j] == 'R') {
                rev = !rev;
            } else if (cmd[j] == 'D') {
                if (nums.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                } else {
                    if (rev) nums.pop_back();
                    else nums.pop_front();
                }
            }
        }
        if (err) continue;
        if (rev) reverse(nums.begin(), nums.end());
        cout << "[";
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j];
            if (j != nums.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }
}