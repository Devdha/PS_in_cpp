#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int memo[1000000];
    int n;
    cin >> n;

    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;
    
    for (int i = 4; i <= n; i++)
    {
        memo[i] = memo[i - 1] + 1;
        if (i % 2 == 0)
            memo[i] = min(memo[i], memo[i / 2] + 1);
        if (i % 3 == 0)
            memo[i] = min(memo[i], memo[i / 3] + 1);
    }
    cout << memo[n];
}