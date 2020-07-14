#include <iostream>
#include	 <vector>
#include <string>

using namespace std;

int commandSize, currentMonth = 0;

int monthSize[13] = { 31,28,31,30,31,30,31,31,30,31,30,31,31 };

vector<vector <string>> month(monthSize[currentMonth]);


int i = 0;

void add(vector<int>& commandValue) {
	string temp;
	cin >> commandValue[i];
	cin >> temp;
	month[commandValue[i] - 1].push_back(temp);
}
void dump(vector<int>& commandValue) {
	cin >> commandValue[i];
	int a = month[commandValue[i] - 1].size();
	cout << a << " ";
	for (auto j : month[commandValue[i] - 1])
	{
		cout << j << " ";
	}
	cout << endl;
}
void next() {
	if (monthSize[currentMonth + 1] < monthSize[currentMonth]) {
		for (int j = monthSize[currentMonth + 1]; j < monthSize[currentMonth]; j++)
		{
			for (int k = 0; k < month[j].size(); k++)
			{
				month[monthSize[currentMonth + 1] - 1].push_back(month[j][k]);
			}
		}
	}
	month.resize(monthSize[currentMonth + 1]);

	currentMonth++;
	currentMonth %= 12;
}

int main() {

	cin >> commandSize;
	vector<string> commandType(commandSize);
	vector<int> commandValue(commandSize);
	for (i = 0; i < commandSize; i++)
	{
		cin >> commandType[i];
		if (commandType[i] == "ADD") { add(commandValue); }
		if (commandType[i] == "DUMP") { dump(commandValue); }
		if (commandType[i] == "NEXT") { next(); }
	}

	return 0;
}