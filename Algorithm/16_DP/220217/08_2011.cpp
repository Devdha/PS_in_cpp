#include <bits/stdc++.h>

using namespace std;

long long DP[5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	DP[0] = 1;
	DP[1] = 1;
	if (str[0] - '0' == 0) 
        cout << 0;
	else {
		for (int i = 2; i <= str.length(); i++) {
			if (str[i - 1] - '0' > 0)
				DP[i] = DP[i - 1] % 1000000;
			int x = (str[i - 2] - '0') * 10 + str[i - 1] - '0';
			if (10 <= x && x <= 26)
				DP[i] = (DP[i] + DP[i - 2]) % 1000000;
		}
		cout << DP[str.size()];
	}
}