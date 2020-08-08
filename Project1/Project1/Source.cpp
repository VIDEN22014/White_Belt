#include <iostream>
#include<vector>
#include <string>
#include <map>

using namespace std;
const string null;

void change_captial(map<string, string>& m) {
	string country, capital, old_capital;
	cin >> country;
	cin >> capital;
	if (!m.count(country)) {
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	}
	else {
		old_capital = m.find(country)->second;
		if (old_capital == capital) {
			cout << "Country " << country << " hasn't changed its capital" << endl;
		}
		else {
			cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
		}
	}
	m[country] = capital;
}
void rename(map<string, string>& m) {
	string old_country, new_country, temp_capital;
	cin >> old_country;
	cin >> new_country;
	if (!m.count(old_country) || old_country== new_country|| m.count(new_country)) {
		cout << "Incorrect rename, skip" << endl;
		return;
	}
	temp_capital = m.find(old_country)->second;
	m.erase(m.find(old_country));
	cout<< "Country "<< old_country <<" with capital "<< temp_capital <<" has been renamed to "<< new_country <<endl;
	m[new_country] = temp_capital;
}
void about(map<string, string>& m) {
	string country;
	cin >> country;
	if (!m.count(country)) {
		cout << "Country "<< country<<" doesn't exist" << endl;
	}
	else {
		cout << "Country " << country << " has capital " << m.find(country)->second<<endl;
	}
}
void dump(const map<string, string>& m) {
	if (m.size()==0) {
		cout << "There are no countries in the world"<<endl;
		return;
	}
	for (auto i : m) {
		cout << i.first << "/" << i.second << " ";
	}
}


int main() {
	string country, capital,operation_name;
	map<string, string> capital_by_country;
	int operation_size;
	cin >> operation_size;
	for (int i = 0; i < operation_size; i++)
	{
		cin >> operation_name;
		if (operation_name == "CHANGE_CAPITAL") { change_captial(capital_by_country); }
		if (operation_name == "RENAME") { rename(capital_by_country); }
		if (operation_name == "ABOUT") { about(capital_by_country); }
		if (operation_name == "DUMP") { dump(capital_by_country); }
	}
	return 0;
}