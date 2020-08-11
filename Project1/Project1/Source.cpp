#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	map<int, set<string>> bus_stops;
	int operation_size, stops_size, counter = 1;
	cin >> operation_size;
	for (int i = 0; i < operation_size; i++)
	{
		cin >> stops_size;

		set<string> stops;

		for (int j = 0; j < stops_size; j++)
		{
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		bool is_exist = false;
		for (auto j : bus_stops)
		{
			if (j.second == stops) {
				cout << "Already exists for " << j.first << endl;
				is_exist = true;
			}
		}
		if (!is_exist) {
			bus_stops[counter] = stops;
			cout << "New bus " << counter << endl;
			counter++;
		}
	}
	return 0;
}