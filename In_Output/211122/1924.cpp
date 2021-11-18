#include <iostream>
#include <string>

using namespace std;

int main()
{
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month;
    int day;
    int total = 0;
    
    cin >> month >> day;
    for (int i = 0; i < month; i++)
        total += days[i];
    total += day;
    cout << week[(total - 1) % 7];
}