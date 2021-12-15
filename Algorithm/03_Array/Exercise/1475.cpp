// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, max;
	int res[9] = {0,};
	string str;

	cin >> n;
	str = to_string(n);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '9')
			res[6]++;
		else
			res[str[i] - '0']++;
	}
	cout << res[8];
	if (res[6] % 2 == 0)
		res[6] /= 2;
	else
		res[6] = res[6] / 2 + 1;
	max = 0;
	for (int i = 0; i < 9; i++)
		max = max < res[i] ? res[i] : max;
	
	cout << max;
}