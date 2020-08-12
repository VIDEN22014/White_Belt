#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void Display(vector<int>v) {
	for (const auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int n;
	vector<int>v;
	cin >> n;
	if (n < 0 || n>1000)return 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), [](int x, int y) {return abs(x) < abs(y); });
	Display(v);
	return 0;
}