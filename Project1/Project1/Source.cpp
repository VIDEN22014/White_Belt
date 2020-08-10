#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> value;
	for (auto i : m) {
		value.insert(i.second);
	}
	return value;
}