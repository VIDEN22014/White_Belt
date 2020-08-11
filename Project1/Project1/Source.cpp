#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	int operation_size;
	cin >> operation_size;
	string operation_name;
	map<string,set<string>> synonims;
	string word1, word2;
	for (int i = 0; i < operation_size; i++)
	{
		cin >> operation_name;
		if (operation_name == "ADD") {
			cin >> word1 >> word2;
			synonims[word1].insert(word2);
			synonims[word2].insert(word1);
		}
		else if (operation_name == "COUNT") {
			cin >> word1;
			cout << synonims[word1].size() << endl;
		}
		else if (operation_name == "CHECK") {
			cin >> word1 >> word2;
			if (synonims[word1].count(word2)==1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}