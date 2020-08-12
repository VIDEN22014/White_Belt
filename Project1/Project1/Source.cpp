#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void Display(vector<string>v) {
	for (const auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int n;
	vector<string>v;
	cin >> n;
	if (n < 0 || n>1000)return 0;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), [](string x, string y) {
		for (auto& i : x)
		{
			i=tolower(i);
		}
		for (auto& i : y)
		{
			i=tolower(i);
		} 
		return x < y;});
	Display(v);
	return 0;
}