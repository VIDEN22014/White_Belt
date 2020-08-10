#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	set<string> str;
	int operation_size;
	cin >> operation_size;
	for (int i = 0; i < operation_size; i++)
	{
		string s;
		cin >> s;
		str.insert(s);
	}
	cout << str.size() << endl;
	return 0;
}