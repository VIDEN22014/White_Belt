#include <iostream>
#include<vector>
#include <string>
#include <map>

using namespace std;
vector<string> bus_order;

void new_bus(map<string, vector<string>>& m) {
	string bus;
	int stops_count;
	cin >> bus >> stops_count;
	bus_order.push_back(bus);
	for (int i = 0; i < stops_count; i++)
	{
		string stop;
		cin >> stop;
		m[bus].push_back(stop);

	}
}
void buses_for_stop(const map<string, vector<string>>& m) {
	bool is_stop = false;
	string stop;
	cin >> stop;
	for (int i = 0; i < bus_order.size(); i++)
	{
		for (int j = 0; j < m.find(bus_order[i])->second.size(); j++)
		{
			if (m.find(bus_order[i])->second[j] == stop) {
				cout << bus_order[i] << " ";
				is_stop = true;
			}
		}
	}
	if (!is_stop || bus_order.size() == 0) {
		cout << "No stop" << endl;
	}
	else { cout << endl; }
}
void stops_for_bus(const map<string, vector<string>>& m) {
	string bus;
	cin >> bus;
	if (m.count(bus) == false) {
		cout << "No bus" << endl;
		return;
	}
	for (int i = 0; i < m.find(bus)->second.size(); i++)
	{
		cout << "Stop " << m.find(bus)->second[i] << ": ";
		bool interchange = false;
		for (auto j : bus_order)
		{
			if (j != bus) {
				
				for (int k = 0; k < m.find(j)->second.size(); k++)
				{
					if (m.find(j)->second[k] == m.find(bus)->second[i]) {
						cout << j << " ";
						interchange = true;
					}
				}	
			}
		}
		if (!interchange) cout << "no interchange";
		cout << endl;
	}
}
void all_buses(const map<string, vector<string>>& m) {
	if (bus_order.size() == 0) {
		cout << "No buses" << endl;
		return;
	}
	for (auto i:m)
	{
		cout << "Bus " << i.first << ": ";
		for (auto j : i.second) {
			cout << j<<" ";
		}
		cout << endl;
	}
}

int main() {
	string operation_name;
	map<string, vector<string>> bus_stops;
	int operation_size;
	cin >> operation_size;
	for (int i = 0; i < operation_size; i++)
	{
		cin >> operation_name;
		if (operation_name == "NEW_BUS") { new_bus(bus_stops); }
		if (operation_name == "BUSES_FOR_STOP") { buses_for_stop(bus_stops); }
		if (operation_name == "STOPS_FOR_BUS") { stops_for_bus(bus_stops); }
		if (operation_name == "ALL_BUSES") { all_buses(bus_stops); }
	}
	return 0;
}