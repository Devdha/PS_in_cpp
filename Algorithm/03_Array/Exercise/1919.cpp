#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1;
string str2;
int s1[26] = {0,};
int s2[26] = {0,};
int cnt = 0;

int main() {
	int res = 0;
	cin >> str1 >> str2;
	for (int i = 0; str1[i] != '\0'; i++) s1[str1[i] - 'a']++;
	for (int i = 0; str2[i] != '\0'; i++) s2[str2[i] - 'a']++;
	for (int i = 0; i < 26; i++) res += abs(s1[i] - s2[i]);
	cout << res;
}

// int main() {
// 	cin >> str1 >> str2;
// 	sort(str1.begin(), str1.end());
// 	sort(str2.begin(), str2.begin());
// 	int len = str1.length();
// 	int i = 0;
// 	while () {
// 		if (str1[i] != str2[i])
// 			str1[i] < str2[i] ? str1.erase(i) : str2.erase(i);
// 		else
// 			i++;
// 	}
// }