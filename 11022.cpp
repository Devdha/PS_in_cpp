#include <iostream>

using namespace std;

int main()
{
    int cnt;
    int num;
    int a;
    int b;

    cin >> num;
    cnt = 1;

    while (cnt <= num)
    {
        cin >> a >> b;
        cout << "Case #" << cnt << ": " << a << " + " << b << " = " << a + b << endl;
        cnt++;
    }
    return 0;
}