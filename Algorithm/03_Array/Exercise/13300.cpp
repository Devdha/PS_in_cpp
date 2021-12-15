#include <iostream>
#include <vector>

using namespace std;
vector<int> m(6);
vector<int> f(6);
int n, k;

int devide(vector<int> &v, int i) {
	if (v[i] % k == 0)
		return v[i] / k;
	else
		return v[i] / k + 1;
}

int main() {
	cin >> n >> k;
	int sex, grade;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> sex >> grade;
		sex ? m[grade - 1]++ : f[grade - 1]++;
	}
	for (int i = 0; i < 6; i++)
	{
		cnt += devide(m, i);
		cnt += devide(f, i);
	}
	cout << cnt;
}